[|LetterInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|LetterInput:X]
Y=[|LetterInput:Y]
W=[|LetterInput:W]
H=[|LetterInput:H]
DefaultValue=#|Letter#
Command1=!WriteKeyValue Variables |Letter "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|SmartSensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|SmartSensorInstanceInput:X]
Y=[|SmartSensorInstanceInput:Y]
W=[|SmartSensorInstanceInput:W]
H=[|SmartSensorInstanceInput:H]
DefaultValue=#|SmartSensorId#
Command1=!WriteKeyValue Variables |SmartSensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|SmartInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|SmartTemperatureIdInput:X]
Y=[|SmartTemperatureIdInput:Y]
W=[|SmartTemperatureIdInput:W]
H=[|SmartTemperatureIdInput:H]
DefaultValue=#SmartInstance#
Command1=!WriteKeyValue Variables SmartInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|SmartTemperatureIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|SmartSensorIdInput:X]
Y=[|SmartSensorIdInput:Y]
W=[|SmartSensorIdInput:W]
H=[|SmartSensorIdInput:H]
DefaultValue=#|SmartTemperatureId#
Command1=!WriteKeyValue Variables |SmartTemperatureId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------

[|Title]
Meter=String
X=10
Y=10R
W=45
H=20
FontSize=12
FontColor=#TextColor#
AntiAlias=1
Text=|
UpdateDivider=-1

[|LetterInput]
Meter=String
X=55
Y=0r
W=20
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|Letter#
LeftMouseUpAction=!CommandMeasure "|LetterInputMeasure" "ExecuteBatch 1-3"

[|LetterSemicolon]
Meter=String
X=75
Y=0r
W=10
H=20
FontSize=12
FontColor=#TextColor#
AntiAlias=1
Text=:
UpdateDivider=-1

[|SmartLabel]
Meter=String
X=85
Y=1r
W=50
H=20
FontSize=10
FontColor=#TextColor#
AntiAlias=1
Text=SMART
UpdateDivider=-1

[|HideTemperatureOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#|SmartOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables |HideTemperature "0" "#@#disks.var"][!WriteKeyValue Variables |SmartOnSelect #ColorOn# "#@#disks.var"][!WriteKeyValue Variables |SmartOffSelect #BackdropColor# "#@#disks.var"][!RefreshGroup Disks]

[|HideTemperatureOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#|SmartOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables |HideTemperature "1" "#@#disks.var"][!WriteKeyValue Variables |SmartOffSelect #ColorOff# "#@#disks.var"][!WriteKeyValue Variables |SmartOnSelect #BackdropColor# "#@#disks.var"][!RefreshGroup Disks]

[|SmartSensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|SmartSensorId#
LeftMouseUpAction=!CommandMeasure "|SmartTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[|SmartSensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|SmartInstance#
LeftMouseUpAction=!CommandMeasure "|SmartSensorIdInputMeasure" "ExecuteBatch 1-3"

[|SmartTemperatureIdLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=1r
W=90
H=19
FontSize=10
Text=Entry ID

[|SmartTemperatureIdInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|SmartTemperatureId#
LeftMouseUpAction=!CommandMeasure "|SmartInstanceInputMeasure" "ExecuteBatch 1-3"

[|ActivitySensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|ActivitySensorInstanceInput:X]
Y=[|ActivitySensorInstanceInput:Y]
W=[|ActivitySensorInstanceInput:W]
H=[|ActivitySensorInstanceInput:H]
DefaultValue=#|ActivitySensorId#
Command1=!WriteKeyValue Variables |ActivitySensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|ActivityInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|ActivityTemperatureIdInput:X]
Y=[|ActivityTemperatureIdInput:Y]
W=[|ActivityTemperatureIdInput:W]
H=[|ActivityTemperatureIdInput:H]
DefaultValue=#ActivityInstance#
Command1=!WriteKeyValue Variables ActivityInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|ActivityReadPercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|SmartSensorIdInput:X]
Y=[|SmartSensorIdInput:Y]
W=[|SmartSensorIdInput:W]
H=[|SmartSensorIdInput:H]
DefaultValue=#|ActivityReadPercentId#
Command1=!WriteKeyValue Variables |ActivityReadPercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[|ActivityWritePercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#TextColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[|SmartSensorIdInput:X]
Y=[|SmartSensorIdInput:Y]
W=[|SmartSensorIdInput:W]
H=[|SmartSensorIdInput:H]
DefaultValue=#|ActivityWritePercentId#
Command1=!WriteKeyValue Variables |ActivityWritePercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------

[|ActivityLabel]
Meter=String
X=85
Y=5R
W=50
H=20
FontSize=10
FontColor=#TextColor#
AntiAlias=1
Text=Activity
UpdateDivider=-1

[|HideActivityOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#|ActivityOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables |HideActivity "0" "#@#disks.var"][!WriteKeyValue Variables |ActivityOnSelect #ColorOn# "#@#disks.var"][!WriteKeyValue Variables |ActivityOffSelect #BackdropColor# "#@#disks.var"][!RefreshGroup Disks]

[|HideActivityOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#|ActivityOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables |HideActivity "1" "#@#disks.var"][!WriteKeyValue Variables |ActivityOffSelect #ColorOff# "#@#disks.var"][!WriteKeyValue Variables |ActivityOnSelect #BackdropColor# "#@#disks.var"][!RefreshGroup Disks]

[|ActivitySensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|ActivitySensorId#
LeftMouseUpAction=!CommandMeasure "|ActivityTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[|ActivitySensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|ActivityInstance#
LeftMouseUpAction=!CommandMeasure "|ActivitySensorIdInputMeasure" "ExecuteBatch 1-3"

[|ActivityUsageReadLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=1r
W=90
H=19
FontSize=10
Text=Read Usage

[|ActivityUsageReadInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|ActivityReadPercentId#
LeftMouseUpAction=!CommandMeasure "|ActivityUsageReadInputMeasure" "ExecuteBatch 1-3"

[|ActivityUsageWriteLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=85
H=19
FontSize=10
Text=Write Usage

[|ActivityUsageWriteInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#TextColor#
AntiAlias=1
SolidColor=#BackdropColor#
Text=#|ActivityWritePercentId#
LeftMouseUpAction=!CommandMeasure "|ActivityUsageWriteInputMeasure" "ExecuteBatch 1-3"
