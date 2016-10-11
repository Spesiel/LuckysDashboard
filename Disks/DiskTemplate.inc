[Disk1Title]
Meter=String
MeterStyle=TextStyle
FontSize=20
X=1
Y=0
W=35
H=28
Text=#Disk1Letter#:
TransformationMatrix=#Scaling#
UpdateDivider=-1

[Disk1TitleMouseClick]
Meter=Image
Solidcolor=#ColorClear#
X=([Disk1Title:X] * #ScaleDisks#)
Y=([Disk1Title:Y] * #ScaleDisks#)
W=([Disk1Title:W] * #ScaleDisks#)
H=([Disk1Title:H] * #ScaleDisks#)
LeftMouseUpAction=["#Disk1Letter#:\"]
UpdateDivider=-1

;------------------------------------------------------------------------------
; Usage display

[Disk1TotalMeasure]
Measure=FreeDiskSpace
Drive=#Disk1Letter#:
Total=1
UpdateDivider=10
IgnoreRemovable=0

[Disk1UsedMeasure]
Measure=FreeDiskSpace
Drive=#Disk1Letter#:
InvertMeasure=1
UpdateDivider=10
IgnoreRemovable=0

[Disk1UsedLabel]
Meter=String
MeterStyle=TextStyle
FontSize=9
MeasureName=Disk1UsedMeasure
X=38
Y=5
W=35
H=12
Percentual=1
NumOfDecimals=0
Text=%1%
TransformationMatrix=#Scaling#

[Disk1TotalLabel]
Meter=String
MeterStyle=TextStyle
FontSize=7
MeasureName=Disk1TotalMeasure
X=38
Y=20
W=35
H=9
AutoScale=2
NumOfDecimals=0
Text=%1
TransformationMatrix=#Scaling#

[Disk1UsedBar]
Meter=Bar
MeasureName=Disk1UsedMeasure
MeterStyle=BarStyle
X=73
Y=23
W=172
H=4
TransformationMatrix=#Scaling#

;------------------------------------------------------------------------------
; Temperature display

[Disk1TemperatureMeasureValue]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#Disk1SmartSensorId#
HWiNFOSensorInstance=#Disk1SmartInstance#
HWiNFOEntryId=#Disk1SmartTemperatureId#
HWiNFOType=CurrentValue
DynamicVariables=1
Disabled=#Disk1HideTemperature#

[Disk1TemperatureMeasureUnit]
Measure=Plugin
Plugin=HWiNFO.dll
HWiNFOSensorId=#Disk1SmartSensorId#
HWiNFOSensorInstance=#Disk1SmartInstance#
HWiNFOEntryId=#Disk1SmartTemperatureId#
HWiNFOType=Units
DynamicVariables=1
Disabled=#Disk1HideTemperature#

[Disk1TemperatureLabel]
Meter=String
MeterStyle=TextStyle
FontSize=8
MeasureName=Disk1TemperatureMeasureValue
MeasureName2=Disk1TemperatureMeasureUnit
X=3
Y=30
W=30
H=10
NumOfDecimals=0
Text=%1%2
TransformationMatrix=#Scaling#
Hidden=#Disk1HideTemperature#
