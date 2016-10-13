;------------------------------------------------------------------------------
; CPU #| Usage

[Cpu|Measure]
Measure=CPU
Processor=(|+1)

[Cpu|Meter]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
X=85
Y=xr
MeasureName=Cpu|Measure
Text=%1%
TransformationMatrix=#Scaling#

[Cpu|TempCoreValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#SystemTempSensorId#
HWiNFOSensorInstance=#SystemTempInstance#
HWiNFOEntryId=#SystemTemp|TemperatureId#
HWiNFOType=CurrentValue
Disabled=#CpuTempDisabled#

[Cpu|TempCoreMeter]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=10
X=247
Y=1r
MeasureName=Cpu|TempCoreValue
MeasureName2=CpuTempCoreUnits
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#SystemTemp#

[Cpu|Bar]
Meter=Bar
MeterStyle=BarStyle
X=90
Y=7r
W=155
H=3
MeasureName=Cpu|Measure
TransformationMatrix=#Scaling#
