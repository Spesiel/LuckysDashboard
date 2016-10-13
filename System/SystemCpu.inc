[Rainmeter]
Group=System
Update=1000

[Metadata]
Name=SystemCpu
Author=Lucky Penny
Information=Displays informations about the cpu(s).
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

; CPU (all cores) Usage

[CpuTitle]
Meter=String
MeterStyle=TextStyle
X=9
Y=0R
Text=CPU
TransformationMatrix=#Scaling#

;------------------------------------------------------------------------------
; CPU (all cores) Usage

[CpuAllMeasure]
Measure=CPU
Disabled=#SystemCpuAverageTextBar#

[CpuAllMeter]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=120
Y=0r
MeasureName=CpuAllMeasure
Text=%1%
TransformationMatrix=#Scaling#
Hidden=#SystemCpuAverageTextBar#

[CpuAllBar]
Meter=Bar
MeterStyle=BarStyle
X=125
Y=6r
W=120
H=7
MeasureName=CpuAllMeasure
TransformationMatrix=#Scaling#
Hidden=#SystemCpuAverageTextBar#

[CpuTempDisabled]
Measure=Calc
Formula=#SystemTemp# + #SystemTempAverage# <2 ? 0:1

[CpuTempCoreUnits]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#SystemTempSensorId#
HWiNFOSensorInstance=#SystemTempInstance#
HWiNFOEntryId=#SystemTemp0TemperatureId#
HWiNFOType=Units
Substitute="":"  ."
UpdateDivider=-1
Disabled=#CpuTempDisabled#

[CpuAllTempMeasure]
Measure=Calc
Formula=#Cpu0TempCoreValue#
DynamicVariables=1
Disabled=#CpuTempDisabled#

[CpuAllTemp]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=10
X=45
Y=([CpuTitle:Y]+35)
MeasureName=CpuAllTempMeasure
MeasureName2=CpuTempCoreUnits
Text=%1%2
Hidden=#SystemTempAverage#

;------------------------------------------------------------------------------
; CPU cores meters

[Systeming]
Measure=Script
ScriptFile=Systeming.lua

@includeGeneratedCpuMeters=generatedCpuMeters.inc
