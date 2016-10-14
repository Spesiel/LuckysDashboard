; Show/Hide Cpu average usage
SystemCpuAverageTextBar=0
SystemCpuAverageTextBarShowSelect=#BackdropColor#
SystemCpuAverageTextBarHideSelect=#ColorClear#

; Show/Hide Cpu fan informations
SystemCpuFan=0
SystemCpuFanShowSelect=#BackdropColor#
SystemCpuFanHideSelect=#ColorClear#

; Show/Hide Cpu clock informations
SystemCpuClock=0
SystemCpuClockShowSelect=#BackdropColor#
SystemCpuClockHideSelect=#ColorClear#

; Show/Hide Cpu average temperature
SystemTempAverage=0
SystemTempAverageOnSelect=100,250,100
SystemTempAverageOffSelect=#BackdropColor#

; Show/Hide Cpu temperature for each individual core
SystemTempPerCore=0
SystemTempPerCoreOnSelect=100,250,100
SystemTempPerCoreOffSelect=#BackdropColor#

;------------------------------------------------------------------------------
; Sensors informations

; Fan informations
SystemFanSensorId=0xf0ec0101
SystemFanInstance=0x0
SystemFanEntryId=0x3000000

; Cpu Clock informations
SystemClockSensorId=0xf0000300
SystemClockInstance=0x0
SystemClockEntryId=0x6000000

; Temperature informations
SystemTempSensorId=0xf0000400
SystemTempInstance=0x0

; Individual cores temperature entry id
SystemTemp|TemperatureId=0x1000000
