;------------------------------------------------------------------------------

[|MeasureTemperatureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTemp|TemperatureId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]

[|MeasureTemperatureUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTemp|TemperatureId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]

;------------------------------------------------------------------------------

[|MeterTemperature]
Meter=String
MeterStyle=TextStyle
FontSize=9
X=5
Y=5R
MeasureName=|MeasureTemperatureValue
MeasureName2=|MeasureTemperatureUnit
Text=%1%2
TransformationMatrix=#Scaling#
