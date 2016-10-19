[|MeasureName]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOType=SensorName
RegExpSubstitute=1
Substitute="^(.*]: )":"","(: .*)$":"","^$":"-- data missing --"
UpdateDivider=-1

[|MeasureCoreClockValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|CoreClockEntryId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureCoreClockValue]

[|MeasureCoreClockUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|CoreClockEntryId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureCoreClockUnit]

[|MeasureCoreUsageValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|CoreUsageEntryId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureCoreUsageValue]

[|MeasureCoreUsageUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|CoreUsageEntryId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureCoreUsageUnit]

[|MeasureTempValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|TempEntryId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureTempValue]

[|MeasureTempUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|TempEntryId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureTempUnit]

[|MeasureFan]
Measure=String
String=#|FanOffRpmPercent#
RegExpSubstitute=1
Substitute="1":"#|FanRpmEntryId#","2":"#|FanPercentEntryId#"

[|MeasureFanDisabled]
Measure=Calc
Formula=#|FanOffRpmPercent#>0?0:1
IfCondition=(|MeasureFanDisabled=1)
IfTrueAction=[!HideMeterGroup |FanOff][!DisableMeasureGroup |FanOff]

[|MeasureFanValue]
Group=|FanOff
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=[|MeasureFan]
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureFanValue]

[|MeasureFanUnit]
Group=|FanOff
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=[|MeasureFan]
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureFanUnit]

[|MeasureNVidiaAmd]
Measure=String
String=#|NVidiaAmd#
RegExpSubstitute=1
Substitute="1":"#|NVidiaMemoryAllocatedEntryId#","2":"#|AMDD3DMemoryDedicated#"

[|MeasureNVidiaAmdDisabled]
Measure=Calc
Formula=#|NVidiaAmd#>0?0:1

[|MeasureNVidiaAmdValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=[|MeasureNVidiaAmd]
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureNVidiaAmdValue]
Disabled=#|MeasureNVidiaAmdDisabled#

[|MeasureNVidiaUsageValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=#|NVidiaMemoryUsageEntryId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureNVidiaUsageValue]
Disabled=[|MeasureNVidiaDisabled]

[|MeasureNVidiaAmdUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SensorId#
HWiNFOSensorInstance=#|CoreInstance#
HWiNFOEntryId=[|MeasureNVidiaAmd]
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!UpdateMeasure |MeasureNVidiaAmdUnit]
Disabled=#|MeasureNVidiaAmdDisabled#

[|MeasureAmdEnabled]
Measure=Calc
Formula=#|NVidiaAmd#<2?0:1

[|MeasureAmdDisabled]
Measure=Calc
Formula=#|NVidiaAmd#<2?1:0

[|MeasureNVidiaEnabled]
Measure=Calc
Formula=#|NVidiaAmd#>1?0:1

[|MeasureNVidiaDisabled]
Measure=Calc
Formula=#|NVidiaAmd#=1?1:0

[|MeasureNVidiaAmdUsage]
Measure=Calc
Formula=[|MeasureAmdEnabled]*([|MeasureNVidiaAmdValue]/#|AMDD3DMemoryTotal#)+[|MeasureNVidiaEnabled]*([|MeasureNVidiaUsageValue])
DynamicVariables=1

;------------------------------------------------------------------------------

[|MeterName]
Meter=String
MeterStyle=TextStyle
StringAlign=Center
FontSize=9
X=125
Y=5R
MeasureName=|MeasureName
TransformationMatrix=#Scaling#

[|MeterCoreClock]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
StringStyle=Normal
FontSize=9
X=245
Y=([|MeterName:Y]+16)
MeasureName=|MeasureCoreClockValue
MeasureName2=|MeasureCoreClockUnit
Text=%1%2 :Clock
TransformationMatrix=#Scaling#

[|MeterCoreUsage]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=5
Y=([|MeterName:Y]+15)
MeasureName=|MeasureCoreUsageValue
MeasureName2=|MeasureCoreUsageUnit
Text=Usage: %1%2
TransformationMatrix=#Scaling#

[|UsageBar]
Meter=Histogram
MeterStyle=HistogramStyle
X=5
Y=([|MeterName:Y]+15)
W=240
H=50
MeasureName=|MeasureCoreUsageValue
TransformationMatrix=#Scaling#

[|MeterTemperature]
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10
Y=4R
MeasureName=|MeasureTempValue
MeasureName2=|MeasureTempUnit
Text=Temp: %1%2
TransformationMatrix=#Scaling#

[|MeterFan]
Group=|FanOff
Meter=String
MeterStyle=TextStyle
FontSize=10
X=10
Y=0R
MeasureName=|MeasureFanValue
MeasureName2=|MeasureFanUnit
Text=Fan: %1%2
TransformationMatrix=#Scaling#

[|MeterMemoryLabel]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=10
X=240
Y=([|MeterTemperature:Y]+7)
Text=:Mem
TransformationMatrix=#Scaling#

[|MeterMemory]
Meter=String
MeterStyle=TextStyle
StringAling=Right
FontSize=10
X=-85r
Y=([|MeterTemperature:Y])
MeasureName=|MeasureNVidiaAmdValue
MeasureName2=|MeasureNVidiaAmdUnit
Text=%1%2
TransformationMatrix=#Scaling#

[|MeterMemoryUsage]
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=10
X=0R
Y=0R
MeasureName=|MeasureNVidiaAmdUsage
Text=%1%
NumOfDecimals=2
TransformationMatrix=#Scaling#

[|TempLine]
Meter=Histogram
MeterStyle=HistogramStyle
GraphStart=Left
X=5
Y=([|MeterFan:Y]+35)
W=117
H=50
MeasureName=|MeasureTempValue
TransformationMatrix=#Scaling#

[|MemLine]
Meter=Histogram
MeterStyle=HistogramStyle
X=128
Y=([|MeterFan:Y]+35)
W=117
H=50
MeasureName=|MeasureNVidiaAmdUsage
TransformationMatrix=#Scaling#
