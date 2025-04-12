/* Porter:
 18, 19, 21, 22, 23, 25, 26, 27,};
// 21, 22, 23, 25, 26, 27,18,19};
*/
// Please read file README.md in the folder containing this example.






// 40kHz parameters
const int pin = 18;
const uint16_t frequency = 40000;          // 40kHz
const uint16_t burstDurationMicros = 500;  // 0.5 ms burst (example)
unsigned long periodMicros = 1000000UL / frequency;
unsigned long halfPeriod = periodMicros / 2;
unsigned long elapsed = 0;

// Function to generate a 40kHz tone burst
void generateToneBurst(uint8_t pin, uint16_t frequency, uint16_t durationMicros) {
  unsigned long periodMicros = 1000000UL / frequency;
  unsigned long halfPeriod = periodMicros / 2;
  unsigned long elapsed = 0;
const uint16_t duty = 50;
  while (elapsed < durationMicros) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(periodMicros*duty/100);
  digitalWrite(pin, LOW);
  delayMicroseconds(periodMicros*(100-duty)/100);
  elapsed += periodMicros;
  }
}














#if CONFIG_FREERTOS_UNICORE
#define TASK_RUNNING_CORE 0
#else
#define TASK_RUNNING_CORE 1
#endif

#define ANALOG_INPUT_PIN A0

#ifndef LED_BUILTIN
#define LED_BUILTIN 13  // Specify the on which is your LED
#endif



struct TaskParams {
  int port;
  int offset;
  int fase;
  int apml;
  const char *navn;
};

static TaskParams params = { 42, 500, 50, 60, "Navn" };



int offset = 500;



// Define two tasks for Blink & AnalogRead.
void TaskBlink(void *pvParameters);

TaskHandle_t analog_read_task_handle;  // You can (don't have to) use this to be able to manipulate a task from somewhere else.
TaskHandle_t taskhandle;               // You can (don't have to) use this to be able to manipulate a task from somewhere else.

// The setup function runs once when you press reset or power on the board.
void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  pinMode(18,OUTPUT);
  Serial.println('halfPeriod',halfPeriod);
  // Set up two tasks to run independently.
  // uint32_t blink_delay = 1000;  // Delay between changing state on LED pin

  static TaskParams params1 = { 18, offset, 50, 60, "task1" };
  xTaskCreate(Task1, "Task11", 2048, &params1, 2, NULL);

  static TaskParams params2 = { 19, offset, 60, 60, "task2" };
  xTaskCreate(Task1, "Task12", 2048, &params2, 2, NULL);

  static TaskParams params3 = { 21, offset, 70, 60, "task3" };
  xTaskCreate(Task1, "Task13", 2048, &params3, 2, NULL);

  static TaskParams params4 = { 22, offset, 150, 60, "task4" };
  xTaskCreate(Task1, "Task13", 2048, &params4, 2, NULL);

  static TaskParams params5 = { 23, offset, 150, 60, "task5" };
  xTaskCreate(Task1, "Task13", 2048, &params5, 2, NULL);

  static TaskParams params6 = { 25, offset, 150, 60, "task6" };
  xTaskCreate(Task1, "Task13", 2048, &params6, 2, NULL);

  static TaskParams params7 = { 26, offset, 150, 60, "task7" };
  xTaskCreate(Task1, "Task13", 2048, &params7, 2, NULL);

  static TaskParams params8 = { 27, offset, 150, 60, "task8" };
  xTaskCreate(Task1, "Task13", 2048, &params8, 2, NULL);

  // Serial.println("Basic Multi Threading Arduino Example\n");
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop() {
//   delay(10);
//   digitalWrite(pin, HIGH);
//   // delayMicroseconds(halfPeriod);
//  delay(100);
//   digitalWrite(pin, LOW);
//   delayMicroseconds(halfPeriod);

   // generateToneBurst(18, frequency, burstDurationMicros);
  //   vTaskDelay(pdMS_TO_TICKS(100));  // Wait 100ms before next burst
  // // if (analog_read_task_handle != NULL) {  // Make sure that the task actually exists
  //   delay(500);
  //   vTaskDelete(analog_read_task_handle);  // Delete task
  //   analog_read_task_handle = NULL;        // prevent calling vTaskDelete on non-existing task
  // }
}


void Task1(void *pvParameters) {  // This is a task.
  // uint32_t blink_delay = *((uint32_t *)pvParameters);
  TaskParams *data = (TaskParams *)pvParameters;  //
  Serial.println("task start...");
  Serial.println(data->port);
  Serial.println(data->offset);
  Serial.println(data->fase);
  Serial.println(data->apml);
  Serial.println(data->navn);
  pinMode(data->port, OUTPUT);
  digitalWrite(data->port, LOW);
  for (;;) {
    // Serial.print("task start...");
    // Serial.print(data->port);
    // Serial.print(" : ");
    // Serial.print(data->fase);
    // Serial.print(" : ");
    // Serial.print(data->apml);
    // Serial.print(" : ");
    Serial.println(data->navn);
    vTaskDelay(data->offset + data->fase);
    generateToneBurst(data->port, frequency, burstDurationMicros);
   // vTaskDelay(pdMS_TO_TICKS(100));  // Wait 100ms before next burst
  // digitalWrite(data->port, HIGH);  // turn the LED on (HIGH is the voltage level)
    vTaskDelay(10);
   // digitalWrite(data->port, LOW);  // turn the LED off by making the voltage LOW
  //  vTaskDelay(500);
  }
}
