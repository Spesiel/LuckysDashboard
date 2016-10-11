[Disk1LetterInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1LetterInput:X]
Y=[Disk1LetterInput:Y]
W=[Disk1LetterInput:W]
H=[Disk1LetterInput:H]
DefaultValue=#Disk1Letter#
Command1=!WriteKeyValue Variables Disk1Letter "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[Disk1SmartSensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartSensorInstanceInput:X]
Y=[Disk1SmartSensorInstanceInput:Y]
W=[Disk1SmartSensorInstanceInput:W]
H=[Disk1SmartSensorInstanceInput:H]
DefaultValue=#Disk1SmartSensorId#
Command1=!WriteKeyValue Variables Disk1SmartSensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[Disk1SmartInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[Disk1SmartTemperatureIdInput:X]
Y=[Disk1SmartTemperatureIdInput:Y]
W=[Disk1SmartTemperatureIdInput:W]
H=[Disk1SmartTemperatureIdInput:H]
DefaultValue=#SmartInstance#
Command1=!WriteKeyValue Variables SmartInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[Disk1SmartTemperatureIdInputMeasure]
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
DefaultValue=#Disk1SmartTemperatureId#
Command1=!WriteKeyValue Variables Disk1SmartTemperatureId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------

[Disk1Title]
Meter=String
X=10
Y=21r
W=45
H=20
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
Text=Disk1
UpdateDivider=-1

[Disk1LetterInput]
Meter=String
X=55
Y=0r
W=20
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1Letter#
LeftMouseUpAction=!CommandMeasure "Disk1LetterInputMeasure" "ExecuteBatch 1-3"

[Disk1LetterSemicolon]
Meter=String
X=75
Y=0r
W=10
H=20
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
Text=:
UpdateDivider=-1

[Disk1SmartLabel]
Meter=String
X=85
Y=1r
W=50
H=20
FontSize=10
FontColor=#ForegroundColor#
AntiAlias=1
Text=SMART
UpdateDivider=-1

[Disk1ShowTemperatureOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#Disk1SmartOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Disk1ShowTemperature "1" "#@#disks.var"][!WriteKeyValue Variables Disk1SmartOnSelect 100,250,100 "#@#disks.var"][!WriteKeyValue Variables Disk1SmartOffSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[Disk1ShowTemperatureOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#Disk1SmartOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Disk1ShowTemperature "0" "#@#disks.var"][!WriteKeyValue Variables Disk1SmartOffSelect 250,100,100 "#@#disks.var"][!WriteKeyValue Variables Disk1SmartOnSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[Disk1SmartSensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartSensorId#
LeftMouseUpAction=!CommandMeasure "Disk1SmartTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[Disk1SmartSensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartInstance#
LeftMouseUpAction=!CommandMeasure "Disk1SmartSensorIdInputMeasure" "ExecuteBatch 1-3"

[Disk1SmartTemperatureIdInput]
Meter=String
X=324
Y=0r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#Disk1SmartTemperatureId#
LeftMouseUpAction=!CommandMeasure "Disk1SmartInstanceInputMeasure" "ExecuteBatch 1-3"

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
Command1=!WriteKeyValue Variables Disk1ActivitySensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

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
Command1=!WriteKeyValue Variables ActivityInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

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
Command1=!WriteKeyValue Variables Disk1ActivityReadPercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

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
Command1=!WriteKeyValue Variables Disk1ActivityWritePercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

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
Command1=!WriteKeyValue Variables Disk1ActivityReadRateId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

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
Command1=!WriteKeyValue Variables Disk1ActivityWriteRateId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------

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

[Disk1ShowActivityOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#Disk1ActivityOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Disk1ShowActivity "1" "#@#disks.var"][!WriteKeyValue Variables Disk1ActivityOnSelect 100,250,100 "#@#disks.var"][!WriteKeyValue Variables Disk1ActivityOffSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[Disk1ShowActivityOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#Disk1ActivityOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables Disk1ShowActivity "0" "#@#disks.var"][!WriteKeyValue Variables Disk1ActivityOffSelect 250,100,100 "#@#disks.var"][!WriteKeyValue Variables Disk1ActivityOnSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

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
