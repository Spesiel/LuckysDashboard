;------------------------------------------------------------------------------

[Cpu1TempRelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayTempDisabled#)>0?1:0
IfCondition=(Cpu1TempRelatedDisabled=1)
IfTrueAction=[!Log "-- Temp is disabled"][!DisableMeasureGroup Cpu1TempRelated][!HideMeterGroup Cpu1TempRelated][!ShowMeter Cpu1MeterBarBelowUsageTempOff]
Disabled=#CpuCoresDisplayDisabled#

[Cpu1GraphRelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayGraphDisabled#)=1?1:0
IfCondition=(Cpu1GraphRelatedDisabled=1)
IfTrueAction=[!Log "-- Graph is disabled"][!HideMeterGroup Cpu1GraphRelated]
Disabled=#CpuCoresDisplayDisabled#

[Cpu1GraphUsageDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayUsageDisabled#+#CpuCoresDisplayGraphDisabled#)>0?1:0
IfCondition=(Cpu1GraphUsageDisabled=1)
IfTrueAction=[!Log "-- Graph: Usage is disabled"][!HideMeter Cpu1MeterAboveUsage]
Disabled=#CpuCoresDisplayDisabled#

[Cpu1GraphTempDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayTempDisabled#+#CpuCoresDisplayGraphDisabled#)>0?1:0
IfCondition=(Cpu1GraphTempDisabled=1)
IfTrueAction=[!Log "-- Graph: Temp is disabled"][!HideMeter Cpu1MeterAboveTemp]
Disabled=#CpuCoresDisplayDisabled#

[Cpu1GraphUnrelatedDisabled]
Measure=Calc
Formula=(#CpuCoresDisplayGraphDisabled#)=0?1:0
IfCondition=(Cpu1GraphUnrelatedDisabled=1)
IfTrueAction=[!Log "-- Not Graph is disabled"][!HideMeterGroup Cpu1GraphUnrelated]
Disabled=#CpuCoresDisplayDisabled#

;CpuCoresDisplayDisabled=0
;CpuCoresDisplayUsageDisabled=0
;CpuCoresDisplayTempDisabled=1
;CpuCoresDisplayGraphDisabled=1

;------------------------------------------------------------------------------

[Cpu1MeasureUsage]
Measure=CPU
Processor=1
Disabled=#CpuCoresDisplayDisabled#

[Cpu1MeasureTemperatureValue]
Group=Cpu1TempRelated
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTempCpu1TemperatureId#
HWiNFOType=CurrentValue
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]
Disabled=#CpuCoresDisplayDisabled#

[Cpu1MeasureTemperatureUnit]
Group=Cpu1TempRelated
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#CpuTempSensorId#
HWiNFOSensorInstance=#CpuTempInstance#
HWiNFOEntryId=#CpuTempCpu1TemperatureId#
HWiNFOType=Units
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Cpus]
Disabled=#CpuCoresDisplayDisabled#

;------------------------------------------------------------------------------

[Cpu1DummyStartPoint]
Meter=Image
X=5
Y=0R
W=240
H=1
SolidColor=#ColorClear#

[Cpu1HistogramUsage]
Group=Cpu1GraphRelated
Meter=Histogram
MeterStyle=HistogramStyle
X=4
Y=1r
W=240
H=50
MeasureName=Cpu1MeasureUsage
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1MeterAboveUsage]
Group=Cpu1GraphRelated
Meter=String
MeterStyle=TextStyle
FontSize=9
X=5
Y=1r
MeasureName=Cpu1MeasureUsage
Text=Usage %1%
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1MeterAboveTemp]
Group=Cpu1GraphRelated|Cpu1TempRelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
StringStyle=Normal
FontSize=8
X=243
Y=0r
MeasureName=Cpu1MeasureTemperatureValue
MeasureName2=Cpu1MeasureTemperatureUnit
Text=%1%2 Temp
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1MeterBelowUsage]
Group=Cpu1GraphUnrelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=9
X=35
Y=-2r
MeasureName=Cpu1MeasureUsage
Text=%1%
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1MeterBarBelowUsageTempOn]
Group=Cpu1GraphUnrelated|Cpu1TempRelated
Meter=Bar
MeterStyle=BarStyle
X=36
Y=1r
W=170
H=11
MeasureName=Cpu1MeasureUsage
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1MeterBarBelowUsageTempOff]
Group=Cpu1GraphUnrelated
Meter=Bar
MeterStyle=BarStyle
X=36
Y=1r
W=208
H=11
MeasureName=Cpu1MeasureUsage
TransformationMatrix=#Scaling#
Hidden=1

[Cpu1MeterBelowTemp]
Group=Cpu1GraphUnrelated|Cpu1TempRelated
Meter=String
MeterStyle=TextStyle
StringAlign=Right
FontSize=9
X=246
Y=-2r
MeasureName=Cpu1MeasureTemperatureValue
MeasureName2=Cpu1MeasureTemperatureUnit
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1GraphRelatedDummyPlaceHolder]
Group=Cpu1GraphRelated
Meter=Image
X=4
Y=([Cpu1HistogramUsage:Y]+6)
W=1
H=50
SolidColor=#ColorClear#
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#

[Cpu1GraphUnrelatedDummyPlaceHolder]
Group=Cpu1GraphUnrelated
Meter=Image
X=10
Y=[Cpu1MeterBelowUsage:Y]
W=1
H=13
SolidColor=#ColorClear#
TransformationMatrix=#Scaling#
Hidden=#CpuCoresDisplayDisabled#
