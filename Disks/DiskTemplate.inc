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

[|TotalMeasure]
Measure=FreeDiskSpace
Drive=#|Letter#:
Total=1
UpdateDivider=10
IgnoreRemovable=0

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

[|TotalLabel]
Meter=String
MeterStyle=TextStyle
FontSize=7
MeasureName=|TotalMeasure
X=38
Y=([|Title:Y]+20)
W=35
H=9
AutoScale=2
NumOfDecimals=0
Text=%1
TransformationMatrix=#Scaling#

[|UsedBar]
Meter=Bar
MeasureName=|UsedMeasure
MeterStyle=BarStyle
X=73
Y=([|Title:Y]+23)
W=171
H=4
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
Disabled=#|HideTemperature#

[|TemperatureMeasureUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|SmartSensorId#
HWiNFOSensorInstance=#|SmartInstance#
HWiNFOEntryId=#|SmartTemperatureId#
HWiNFOType=Units
DynamicVariables=1
Disabled=#|HideTemperature#

[|TemperatureLabel]
Meter=String
MeterStyle=TextStyle
FontSize=8
MeasureName=|TemperatureMeasureValue
MeasureName2=|TemperatureMeasureUnit
X=3
Y=([|Title:Y]+30)
W=30
H=10
NumOfDecimals=0
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#|HideTemperature#

;------------------------------------------------------------------------------
; Activity display

[|ActivityReadMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|ActivitySensorId#
HWiNFOSensorInstance=#|ActivityInstance#
HWiNFOEntryId=#|ActivityReadPercentId#
HWiNFOType=CurrentValue
DynamicVariables=1
Disabled=#|HideActivity#

[|ActivityReadHistogram]
Meter=Histogram
MeterStyle=HistogramStyle
MeasureName=|ActivityReadMeasureValue
X=73
Y=([|Title:Y]+4)
W=171
H=19
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#

[|ActivityWriteMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#|ActivitySensorId#
HWiNFOSensorInstance=#|ActivityInstance#
HWiNFOEntryId=#|ActivityWritePercentId#
HWiNFOType=CurrentValue
DynamicVariables=1
Disabled=#|HideActivity#

[|ActivityWriteHistogram]
Meter=Histogram
MeterStyle=HistogramStyle
Flip=1
MeasureName=|ActivityWriteMeasureValue
X=73
Y=([|UsedBar:Y]+4)
W=171
H=19
TransformationMatrix=#Scaling#
Hidden=#|HideActivity#

[|Dummy]
Meter=Image
X=3
Y=([|TemperatureLabel:H]>[|ActivityWriteHistogram:H]?[|Title:Y]+30:[|UsedBar:Y]+4)
W=30
H=([|TemperatureLabel:H]>[|ActivityWriteHistogram:H]?[|TemperatureLabel:H]:[|ActivityWriteHistogram:H])
TransformationMatrix=#Scaling#
