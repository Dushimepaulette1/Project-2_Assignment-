#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Device {
    char name[30];
    int type;
    union {
        float temperature;
        int pressure;
        float voltage;
    } reading;
};

void temperature_monitor(struct Device* currentDevice) {
    printf("[Thermometer] %s reading: %.2f C\n", currentDevice->name, currentDevice->reading.temperature);
    if (currentDevice->reading.temperature > 40.0) {
        printf("  -> WARNING: High temperature detected!\n");
    }
}

void pressure_monitor(struct Device* currentDevice) {
    printf("[Barometer] %s reading: %d Pa\n", currentDevice->name, currentDevice->reading.pressure);
    if (currentDevice->reading.pressure > 100000) {
        printf("  -> WARNING: High pressure detected!\n");
    }
}

void battery_monitor(struct Device* currentDevice) {
    printf("[Voltmeter] %s reading: %.2f V\n", currentDevice->name, currentDevice->reading.voltage);
    if (currentDevice->reading.voltage < 3.0) {
        printf("  -> WARNING: Low voltage detected!\n");
    }
}

void custom_maintenance_monitor(struct Device* currentDevice) {
    printf("[Diagnostic] Running maintenance check on %s...\n", currentDevice->name);
    if (currentDevice->type == 0 && currentDevice->reading.temperature < 0.0) {
         printf("  -> ALERT: Freezing conditions. Heating required.\n");
    } else if (currentDevice->type == 1 && currentDevice->reading.pressure < 90000) {
         printf("  -> ALERT: Severe pressure drop. Leak possible.\n");
    } else if (currentDevice->type == 2 && currentDevice->reading.voltage > 4.5) {
         printf("  -> ALERT: Overvoltage. Risk of short circuit.\n");
    } else {
         printf("  -> Status: Normal operational range.\n");
    }
}

void process_device(struct Device* currentDevice, void (*callback)(struct Device*)) {
    callback(currentDevice);
}

int main() {
    srand(time(NULL));
    int totalSimulations = 10;
    
    struct Device* networkDevices = (struct Device*)malloc(totalSimulations * sizeof(struct Device));
    struct Device* devicePointer = networkDevices;
    
    for (int i = 0; i < totalSimulations; i++) {
        devicePointer->type = rand() % 3;
        
        if (devicePointer->type == 0) {
            strcpy(devicePointer->name, "Factory_Thermometer");
            devicePointer->reading.temperature = (rand() % 600 - 100) / 10.0; 
        } else if (devicePointer->type == 1) {
            strcpy(devicePointer->name, "Pipe_Barometer");
            devicePointer->reading.pressure = 85000 + (rand() % 20000); 
        } else {
            strcpy(devicePointer->name, "System_Battery");
            devicePointer->reading.voltage = (rand() % 60) / 10.0; 
        }
        devicePointer++;
    }

    devicePointer = networkDevices;
    printf("--- Commencing Device Monitoring Simulation ---\n\n");
    
    for (int i = 0; i < totalSimulations; i++) {
        if (devicePointer->type == 0) {
            process_device(devicePointer, temperature_monitor);
        } else if (devicePointer->type == 1) {
            process_device(devicePointer, pressure_monitor);
        } else if (devicePointer->type == 2) {
            process_device(devicePointer, battery_monitor);
        }
        
        if (i % 4 == 0) {
            process_device(devicePointer, custom_maintenance_monitor);
        }
        
        devicePointer++;
    }

    free(networkDevices);
    return 0;
}
