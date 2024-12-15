#include <iostream>
#include <vector>
#include <algorithm>

class DisplayDevice {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~DisplayDevice() {}
};

class CurrentConditionsDisplay : public DisplayDevice {
public:
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Current conditions: " << temperature << "C, " 
                  << humidity << "% humidity, " << pressure << " pressure." << std::endl;
    }
};

class StatisticsDisplay : public DisplayDevice {
public:
    void update(float temperature, float humidity, float pressure) override {
        static float totalTemp = 0;
        static int count = 0;
        static float maxTemp = -1000, minTemp = 1000;
        
        totalTemp += temperature;
        count++;
        
        if (temperature > maxTemp) maxTemp = temperature;
        if (temperature < minTemp) minTemp = temperature;

        float avgTemp = totalTemp / count;
        
        std::cout << "Statistics: Avg Temp: " << avgTemp << "C, Max Temp: " 
                  << maxTemp << "C, Min Temp: " << minTemp << "C" << std::endl;
    }
};

class ForecastDisplay : public DisplayDevice {
public:
    void update(float temperature, float humidity, float pressure) override {
        if (pressure > 1020) {
            std::cout << "Forecast: Good weather ahead!" << std::endl;
        } else {
            std::cout << "Forecast: Bad weather ahead!" << std::endl;
        }
    }
};

class WeatherStation {
private:
    std::vector<DisplayDevice*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void addObserver(DisplayDevice* observer) {
        observers.push_back(observer);
    }

    void removeObserver(DisplayDevice* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setWeatherData(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }

    void notifyObservers() {
        for (DisplayDevice* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
};

int main() {
    WeatherStation weatherStation;

    CurrentConditionsDisplay currentDisplay;
    StatisticsDisplay statisticsDisplay;
    ForecastDisplay forecastDisplay;

    weatherStation.addObserver(&currentDisplay);
    weatherStation.addObserver(&statisticsDisplay);
    weatherStation.addObserver(&forecastDisplay);

    std::cout << "First weather update:"<<std::endl;
    weatherStation.setWeatherData(25.0f, 65.0f, 1018.0f); 

    std::cout << "Second weather update:"<<std::endl;
    weatherStation.setWeatherData(28.0f, 70.0f, 1022.0f);

    std::cout << "Third weather update:"<<std::endl;
    weatherStation.setWeatherData(22.0f, 75.0f, 1015.0f);

    weatherStation.removeObserver(&forecastDisplay);

    std::cout << "After removing Forecast Display:"<<std::endl;
    weatherStation.setWeatherData(30.0f, 60.0f, 1025.0f);

    return 0;
}
