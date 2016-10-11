[%sLetterInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sLetterInput:X]
Y=[%sLetterInput:Y]
W=[%sLetterInput:W]
H=[%sLetterInput:H]
DefaultValue=#%sLetter#
Command1=!WriteKeyValue Variables %sLetter "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sSmartSensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorInstanceInput:X]
Y=[%sSmartSensorInstanceInput:Y]
W=[%sSmartSensorInstanceInput:W]
H=[%sSmartSensorInstanceInput:H]
DefaultValue=#%sSmartSensorId#
Command1=!WriteKeyValue Variables %sSmartSensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sSmartInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartTemperatureIdInput:X]
Y=[%sSmartTemperatureIdInput:Y]
W=[%sSmartTemperatureIdInput:W]
H=[%sSmartTemperatureIdInput:H]
DefaultValue=#SmartInstance#
Command1=!WriteKeyValue Variables SmartInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sSmartTemperatureIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorIdInput:X]
Y=[%sSmartSensorIdInput:Y]
W=[%sSmartSensorIdInput:W]
H=[%sSmartSensorIdInput:H]
DefaultValue=#%sSmartTemperatureId#
Command1=!WriteKeyValue Variables %sSmartTemperatureId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------

[%sTitle]
Meter=String
X=10
Y=21r
W=45
H=20
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
Text=%s
UpdateDivider=-1

[%sLetterInput]
Meter=String
X=55
Y=0r
W=20
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sLetter#
LeftMouseUpAction=!CommandMeasure "%sLetterInputMeasure" "ExecuteBatch 1-3"

[%sLetterSemicolon]
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

[%sSmartLabel]
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

[%sShowTemperatureOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#%sSmartOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables %sShowTemperature "1" "#@#disks.var"][!WriteKeyValue Variables %sSmartOnSelect 100,250,100 "#@#disks.var"][!WriteKeyValue Variables %sSmartOffSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[%sShowTemperatureOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#%sSmartOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables %sShowTemperature "0" "#@#disks.var"][!WriteKeyValue Variables %sSmartOffSelect 250,100,100 "#@#disks.var"][!WriteKeyValue Variables %sSmartOnSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[%sSmartSensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sSmartSensorId#
LeftMouseUpAction=!CommandMeasure "%sSmartTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[%sSmartSensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sSmartInstance#
LeftMouseUpAction=!CommandMeasure "%sSmartSensorIdInputMeasure" "ExecuteBatch 1-3"

[%sSmartTemperatureIdInput]
Meter=String
X=324
Y=0r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sSmartTemperatureId#
LeftMouseUpAction=!CommandMeasure "%sSmartInstanceInputMeasure" "ExecuteBatch 1-3"

[%sActivitySensorIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sActivitySensorInstanceInput:X]
Y=[%sActivitySensorInstanceInput:Y]
W=[%sActivitySensorInstanceInput:W]
H=[%sActivitySensorInstanceInput:H]
DefaultValue=#%sActivitySensorId#
Command1=!WriteKeyValue Variables %sActivitySensorId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sActivityInstanceInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sActivityTemperatureIdInput:X]
Y=[%sActivityTemperatureIdInput:Y]
W=[%sActivityTemperatureIdInput:W]
H=[%sActivityTemperatureIdInput:H]
DefaultValue=#ActivityInstance#
Command1=!WriteKeyValue Variables ActivityInstance "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sActivityReadPercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorIdInput:X]
Y=[%sSmartSensorIdInput:Y]
W=[%sSmartSensorIdInput:W]
H=[%sSmartSensorIdInput:H]
DefaultValue=#%sActivityReadPercentId#
Command1=!WriteKeyValue Variables %sActivityReadPercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sActivityWritePercentIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorIdInput:X]
Y=[%sSmartSensorIdInput:Y]
W=[%sSmartSensorIdInput:W]
H=[%sSmartSensorIdInput:H]
DefaultValue=#%sActivityWritePercentId#
Command1=!WriteKeyValue Variables %sActivityWritePercentId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sActivityReadRateIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorIdInput:X]
Y=[%sSmartSensorIdInput:Y]
W=[%sSmartSensorIdInput:W]
H=[%sSmartSensorIdInput:H]
DefaultValue=#%sActivityReadRateId#
Command1=!WriteKeyValue Variables %sActivityReadRateId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

[%sActivityWriteRateIdInputMeasure]
Measure=Plugin
Plugin=InputText
SolidColor=#ForegroundColor#
FontColor=#BackgroundColor#
FontFace=Seqoe UI
FontSize=12
X=[%sSmartSensorIdInput:X]
Y=[%sSmartSensorIdInput:Y]
W=[%sSmartSensorIdInput:W]
H=[%sSmartSensorIdInput:H]
DefaultValue=#%sActivityWriteRateId#
Command1=!WriteKeyValue Variables %sActivityWriteRateId "$UserInput$" "#@#disks.var"
Command2=!RefreshGroup Disks

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------

[%sActivityLabel]
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

[%sShowActivityOn]
Meter=Image
X=140
Y=0r
W=14
H=14
SolidColor=#%sActivityOnSelect#
LeftMouseUpAction=[!WriteKeyValue Variables %sShowActivity "1" "#@#disks.var"][!WriteKeyValue Variables %sActivityOnSelect 100,250,100 "#@#disks.var"][!WriteKeyValue Variables %sActivityOffSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[%sShowActivityOff]
Meter=Image
X=160
Y=0r
W=14
H=14
SolidColor=#%sActivityOffSelect#
LeftMouseUpAction=[!WriteKeyValue Variables %sShowActivity "0" "#@#disks.var"][!WriteKeyValue Variables %sActivityOffSelect 250,100,100 "#@#disks.var"][!WriteKeyValue Variables %sActivityOnSelect #ForegroundColorDimMin# "#@#disks.var"][!RefreshGroup Disks]

[%sActivitySensorIdInput]
Meter=String
X=190
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivitySensorId#
LeftMouseUpAction=!CommandMeasure "%sActivityTemperatureIdInputMeasure" "ExecuteBatch 1-3"

[%sActivitySensorInstanceInput]
Meter=String
X=287
Y=0r
W=35
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivityInstance#
LeftMouseUpAction=!CommandMeasure "%sActivitySensorIdInputMeasure" "ExecuteBatch 1-3"

[%sActivityUsageReadLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=1r
W=90
H=19
FontSize=10
Text=Read Usage

[%sActivityUsageReadInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivityReadPercentId#
LeftMouseUpAction=!CommandMeasure "%sActivityUsageReadInputMeasure" "ExecuteBatch 1-3"

[%sActivityUsageWriteLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=85
H=19
FontSize=10
Text=Write Usage

[%sActivityUsageWriteInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivityWritePercentId#
LeftMouseUpAction=!CommandMeasure "%sActivityUsageWriteInputMeasure" "ExecuteBatch 1-3"

[%sActivityRateReadLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=90
H=19
FontSize=10
Text=Read Rate

[%sActivityRateReadInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivityReadRateId#
LeftMouseUpAction=!CommandMeasure "%sActivityRateReadInputMeasure" "ExecuteBatch 1-3"

[%sActivityRateWriteLabel]
Meter=String
MeterStyle=TextStyle
StringStyle=Normal
X=324
Y=5R
W=90
H=19
FontSize=10
Text=Write Rate

[%sActivityRateWriteInput]
Meter=String
X=409
Y=-1r
W=95
H=19
FontSize=12
FontColor=#ForegroundColor#
AntiAlias=1
SolidColor=#ForegroundColorDimMin#
Text=#%sActivityWriteRateId#
LeftMouseUpAction=!CommandMeasure "%sActivityRateWriteInputMeasure" "ExecuteBatch 1-3"
