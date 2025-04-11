/* Basic Multi Threading Arduino Example
   This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
// Please read file README.md in the folder containing this example.

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

static TaskParams params = { 42, 500,50, 60, "Navn" };



int offset=500;



// Define two tasks for Blink & AnalogRead.
void TaskBlink(void *pvParameters);

TaskHandle_t analog_read_task_handle;  // You can (don't have to) use this to be able to manipulate a task from somewhere else.
TaskHandle_t taskhandle;               // You can (don't have to) use this to be able to manipulate a task from somewhere else.

// The setup function runs once when you press reset or power on the board.
void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  // Set up two tasks to run independently.
  uint32_t blink_delay = 1000;  // Delay between changing state on LED pin

  static TaskParams params1 = { 25, offset,50, 60, "task1" };
  xTaskCreate(Task1, "Task11", 2048, &params1, 2, NULL);

  static TaskParams params2 = { 26, offset,100, 60, "task2" };
  xTaskCreate(Task1, "Task12", 2048, &params2, 2, NULL);

  static TaskParams params3 = { 27, offset,150, 60, "task3" };
  xTaskCreate(Task1, "Task13", 2048, &params3, 2, NULL);

  static TaskParams params4 = { 27, offset,150, 60, "task4" };
  xTaskCreate(Task1, "Task13", 2048, &params4, 2, NULL);

    static TaskParams params5 = { 27,offset, 150, 60, "task5" };
  xTaskCreate(Task1, "Task13", 2048, &params5, 2, NULL);

    static TaskParams params6 = { 27, offset,150, 60, "task6" };
  xTaskCreate(Task1, "Task13", 2048, &params6, 2, NULL);

    static TaskParams params7 = { 27, offset,150, 60, "task7" };
  xTaskCreate(Task1, "Task13", 2048, &params7, 2, NULL);

    static TaskParams params8 = { 27, offset,150, 60, "task8" };
  xTaskCreate(Task1, "Task13", 2048, &params8, 2, NULL);

  Serial.println("Basic Multi Threading Arduino Example\n");
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop() {
  // if (analog_read_task_handle != NULL) {  // Make sure that the task actually exists
  //   delay(10000);
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
  for (;;) {
    // Serial.print("task start...");
    // Serial.print(data->port);
    // Serial.print(" : ");
    // Serial.print(data->fase);
    // Serial.print(" : ");
    // Serial.print(data->apml);
    // Serial.print(" : ");
     Serial.println(data->navn);

    digitalWrite(data->port, HIGH);  // turn the LED on (HIGH is the voltage level)
    vTaskDelay(data->offset+data->fase);
    digitalWrite(data->port, LOW);  // turn the LED off by making the voltage LOW
   // vTaskDelay(500);
  }
}
