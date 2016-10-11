[Disk1ActivitySensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1ActivitySensorInstanceInput:X]
Y=[Disk1ActivitySensorInstanceInput:Y]
W=[Disk1ActivitySensorInstanceInput:W]
H=[Disk1ActivitySensorInstanceInput:H]
DefaultValue=#Disk1ActivitySensorId#
Command1=!WriteKeyValue Variables Disk1ActivitySensorId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1ActivityInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1ActivityTemperatureIdInput:X]
Y=[Disk1ActivityTemperatureIdInput:Y]
W=[Disk1ActivityTemperatureIdInput:W]
H=[Disk1ActivityTemperatureIdInput:H]
DefaultValue=#ActivityInstance#
Command1=!WriteKeyValue Variables ActivityInstance "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1ActivityReadPercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorIdInput:X]
Y=[Disk1SmartSensorIdInput:Y]
W=[Disk1SmartSensorIdInput:W]
H=[Disk1SmartSensorIdInput:H]
DefaultValue=#Disk1ActivityReadPercentId#
Command1=!WriteKeyValue Variables Disk1ActivityReadPercentId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1ActivityWritePercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorIdInput:X]
Y=[Disk1SmartSensorIdInput:Y]
W=[Disk1SmartSensorIdInput:W]
H=[Disk1SmartSensorIdInput:H]
DefaultValue=#Disk1ActivityWritePercentId#
Command1=!WriteKeyValue Variables Disk1ActivityWritePercentId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1ActivityReadRateIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorIdInput:X]
Y=[Disk1SmartSensorIdInput:Y]
W=[Disk1SmartSensorIdInput:W]
H=[Disk1SmartSensorIdInput:H]
DefaultValue=#Disk1ActivityReadRateId#
Command1=!WriteKeyValue Variables Disk1ActivityReadRateId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

[Disk1ActivityWriteRateIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorIdInput:X]
Y=[Disk1SmartSensorIdInput:Y]
W=[Disk1SmartSensorIdInput:W]
H=[Disk1SmartSensorIdInput:H]
DefaultValue=#Disk1ActivityWriteRateId#
Command1=!WriteKeyValue Variables Disk1ActivityWriteRateId "$UserInput$" "#@#HWiNFO.inc"
Command2=!Refresh #CURRENTCONFIG#
Command3=!Refresh #Disk1SkinLoc#

;---------------------------------------

[Disk1ActivityLabel]
Meter=String
X=85
Y=5R
W=50
H=20
FontSize=10
FontColor=#ForegroundColor#
AntiAlias=1
Text=Activity
UpdateDivider=-1

[meterSelect1activityOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#DiskColor1tempOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables 1_DriveTempOnOff "0" "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOnSelect #colorGreen# "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOffSelect #colorWhiteDimMin# "#@#globalsettings.inc"][!Refresh #CURRENTCONFIG#][!Refresh #Disk1SkinLoc#]

[meterSelect1activityOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#DiskColor1tempOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables 1_DriveTempOnOff "1" "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOffSelect #colorRed# "#@#globalsettings.inc"][!WriteKeyValue Variables DiskColor1tempOnSelect #colorWhiteDimMin# "#@#globalsettings.inc"][!Refresh #CURRENTCONFIG#][!Refresh #Disk1SkinLoc#]

[Disk1ActivitySensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivitySensorId#
LeftMouseUpAction=!CommandMeasure "Disk1ActivityTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[Disk1ActivitySensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivityInstance#
LeftMouseUpAction=!CommandMeasure "Disk1ActivitySensorIdInputMeasure" "ExecuteBatch 1-3"

[Disk1ActivityUsageReadLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=1r
W=90
H=19
FontSize=10
Text=Read Usage

[Disk1ActivityUsageReadInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivityReadPercentId#
LeftMouseUpAction=!CommandMeasure "Disk1ActivityUsageReadInputMeasure" "ExecuteBatch 1-3"

[Disk1ActivityUsageWriteLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=85
H=19
FontSize=10
Text=Write Usage

[Disk1ActivityUsageWriteInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivityWritePercentId#
LeftMouseUpAction=!CommandMeasure "Disk1ActivityUsageWriteInputMeasure" "ExecuteBatch 1-3"

[Disk1ActivityRateReadLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=90
H=19
FontSize=10
Text=Read Rate

[Disk1ActivityRateReadInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivityReadRateId#
LeftMouseUpAction=!CommandMeasure "Disk1ActivityRateReadInputMeasure" "ExecuteBatch 1-3"

[Disk1ActivityRateWriteLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=90
H=19
FontSize=10
Text=Write Rate

[Disk1ActivityRateWriteInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1ActivityWriteRateId#
LeftMouseUpAction=!CommandMeasure "Disk1ActivityRateWriteInputMeasure" "ExecuteBatch 1-3"
