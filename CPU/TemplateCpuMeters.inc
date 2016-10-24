;------------------------------------------------------------------------------

[|TempRelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayTempDisabled#)>0?1:0
IfCondition=(|TempRelatedDisabled=1)
IfTrueAction=[!DisableMeasureGroup |TempRelated][!HideMeterGroup |TempRelated][!ShowMeter |MeterBarBelowUsageTempOff]
Disabled=#CpuCoresDisplayDisabled#

[|GraphRelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayGraphDisabled#)=1?1:0
IfCondition=(|GraphRelatedDisabled=1)
IfTrueAction=[!HideMeterGroup |GraphRelated]
Disabled=#CpuCoresDisplayDisabled#

[|GraphUsageDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayUsageDisabled#+#CpuCoresDisplayGraphDisabled#)>0?1:0
IfCondition=(|GraphUsageDisabled=1)
IfTrueAction=[!HideMeter |MeterAboveUsage]
Disabled=#CpuCoresDisplayDisabled#

[|GraphTempDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayTempDisabled#+#CpuCoresDisplayGraphDisabled#)>0?1:0
IfCondition=(|GraphTempDisabled=1)
IfTrueAction=[!HideMeter |MeterAboveTemp]
Disabled=#CpuCoresDisplayDisabled#

[|GraphUnrelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayGraphDisabled#)=0?1:0
IfCondition=(|GraphUnrelatedDisabled=1)
IfTrueAction=[!HideMeterGroup |GraphUnrelated]
Disabled=#CpuCoresDisplayDisabled#

;CpuCoresDisplayDisabled=0
;CpuCoresDisplayUsageDisabled=0
;CpuCoresDisplayTempDisabled=1
;CpuCoresDisplayGraphDisabled=1

;------------------------------------------------------------------------------

[|MeasureUsage]
Measure=CPU
Processor=1
Disabled=#CpuCoresDisplayDisabled#

[|MeasureTemperatureValue]
Group=|TempRelated
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTemp|TemperatureId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]
IfMatch2=HWI_ERROR_ENTRY_NOT_Connected
IfMatchAction2=[!RefreshGroup Cpus]
Disabled=#CpuCoresDisplayDisabled#

[|MeasureTemperatureUnit]
Group=|TempRelated
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTemp|TemperatureId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]
IfMatch2=HWI_ERROR_ENTRY_NOT_Connected
IfMatchAction2=[!RefreshGroup Cpus]
Disabled=#CpuCoresDisplayDisabled#

;------------------------------------------------------------------------------

[|DummyStartPoint]
Meter=Image
X=5
Y=0R
W=1
H=1
SolidColor=#ColorClear#

[|HistogramUsage]
Group=|GraphRelated
Meter=Histogram
MeterStyle=HistogramStyle
X=4
Y=1r
W=240
H=50
MeasureName=|MeasureUsage
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|MeterAboveUsage]
Group=|GraphRelated
Meter=String
MeterStyle=TextStyle
FontSize=9
X=5
Y=1r
MeasureName=|MeasureUsage
Text=Usage %1%
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|MeterAboveTemp]
Group=|GraphRelated||TempRelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
StringStyle=Normal
FontSize=8
X=243
Y=0r
MeasureName=|MeasureTemperatureValue
MeasureName2=|MeasureTemperatureUnit
Text=%1%2 Temp
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|MeterBelowUsage]
Group=|GraphUnrelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=9
X=35
Y=-2r
MeasureName=|MeasureUsage
Text=%1%
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|MeterBarBelowUsageTempOn]
Group=|GraphUnrelated||TempRelated
Meter=Bar
MeterStyle=BarStyle
X=36
Y=1r
W=170
H=11
MeasureName=|MeasureUsage
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|MeterBarBelowUsageTempOff]
Group=|GraphUnrelated
Meter=Bar
MeterStyle=BarStyle
X=36
Y=1r
W=208
H=11
MeasureName=|MeasureUsage
TransformationMatrix=#Scaling#
Hidden=1

[|MeterBelowTemp]
Group=|GraphUnrelated||TempRelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=9
X=246
Y=-2r
MeasureName=|MeasureTemperatureValue
MeasureName2=|MeasureTemperatureUnit
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|GraphRelatedDummyPlaceHolder]
Group=|GraphRelated
Meter=Image
X=4
Y=([|HistogramUsage:Y]+6)
W=1
H=50
SolidColor=#ColorClear#
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[|GraphUnrelatedDummyPlaceHolder]
Group=|GraphUnrelated
Meter=Image
X=4
Y=[|MeterBelowUsage:Y]
W=1
H=13
SolidColor=#ColorClear#
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#
