[|Title]
Meter=String
MeterStyle=TextStyle
FontSize=20
X=1
Y=0R
W=35
H=28
Text=#|Letter#:
TransformationMatrix=#Scaling#
UpdateDivider=-1

[|TitleMouseClick]
Meter=Image
Solidcolor=#ColorClear#
X=([|Title:X] * #ScaleDisks#)
Y=([|Title:Y] * #ScaleDisks#)
W=([|Title:W] * #ScaleDisks#)
H=([|Title:H] * #ScaleDisks#)
LeftMouseUpAction=["#|Letter#:\"]
UpdateDivider=-1

;------------------------------------------------------------------------------
; Usage display

[|UsedMeasure]
Measure=FreeDiskSpace
Drive=#|Letter#:
InvertMeasure=1
UpdateDivider=10
IgnoreRemovable=0

[|UsedLabel]
Meter=String
MeterStyle=TextStyle
FontSize=9
MeasureName=|UsedMeasure
X=38
Y=([|Title:Y]+5)
W=35
H=12
Percentual=1
NumOfDecimals=0
Text=%1%
TransformationMatrix=#Scaling#

;------------------------------------------------------------------------------
; Temperature display

[|TemperatureMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SmartSensorId#
HWiNFOSensorInstance=#|SmartInstance#
HWiNFOEntryId=#|SmartTemperatureId#
HWiNFOType=CurrentValue
DynamicVariables=1
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Disks]
Disabled=#|HideTemperature#

[|TemperatureMeasureUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SmartSensorId#
HWiNFOSensorInstance=#|SmartInstance#
HWiNFOEntryId=#|SmartTemperatureId#
HWiNFOType=Units
DynamicVariables=1
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Disks]
Disabled=#|HideTemperature#

;------------------------------------------------------------------------------
; Activity display

[|ActivityReadPercentMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|ActivitySensorId#
HWiNFOSensorInstance=#|ActivityInstance#
HWiNFOEntryId=#|ActivityReadPercentId#
HWiNFOType=CurrentValue
DynamicVariables=1
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Disks]
Disabled=#|HideActivity#

[|ActivityReadRateMeasure]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Read Bytes/sec
PerfMonInstance=#|Letter#:

[|ActivityWritePercentMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|ActivitySensorId#
HWiNFOSensorInstance=#|ActivityInstance#
HWiNFOEntryId=#|ActivityWritePercentId#
HWiNFOType=CurrentValue
DynamicVariables=1
IfMatch=HWI_ERROR_ENTRY_NOT_FOUND
IfMatchAction=[!RefreshGroup Disks]
Disabled=#|HideActivity#

[|ActivityWriteRateMeasure]
Measure=Plugin
Plugin=PerfMon
PerfMonObject=LogicalDisk
PerfMonCounter=Disk Write Bytes/sec
PerfMonInstance=#|Letter#:

;------------------------------------------------------------------------------
; Main compononents

[|UsedBar]
Meter=Bar
MeasureName=|UsedMeasure
MeterStyle=BarStyle
X=73
Y=([|Title:Y]+24)
W=171
H=4
TransformationMatrix=#Scaling#

[|ActivityReadPercentHistogram]
Meter=Histogram
MeterStyle=HistogramStyle
MeasureName=|ActivityReadPercentMeasureValue
X=73
Y=([|Title:Y]+4)
W=171
H=19
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#

[|TemperatureLabel]
Meter=String
MeterStyle=TextStyle
FontSize=8
MeasureName=|TemperatureMeasureValue
MeasureName2=|TemperatureMeasureUnit
X=38
Y=([|Title:Y]+20)
W=30
H=10
NumOfDecimals=0
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#|HideTemperature#

[|ActivityWritePercentHistogram]
Meter=Histogram
MeterStyle=HistogramStyle
Flip=1
MeasureName=|ActivityWritePercentMeasureValue
X=73
Y=([|Title:Y]+29)
W=171
H=19
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#

[|ActivityReadRateLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
FontSize=7
MeasureName=|ActivityReadRateMeasure
X=73
Y=([|Title:Y]+4)
Text=R %1Bps
AutoScale=1
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#

[|ActivityWriteRateLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
FontSize=7
MeasureName=|ActivityWriteRateMeasure
X=73
Y=([|UsedBar:Y]+10)
W=171
H=19
Text=W %1Bps
AutoScale=1
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#
