[Metadata]
Name=UptimeScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Uptime widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;------------------------------------------------------------------------------
; Measures

[UptimeScale_MeasureScale]
Measure=Calc
Formula=#ScaleUptime#
MaxValue=2.0
MinValue=0.9

[UptimeScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleUptime# < 2.0 ? #ScaleUptime# + 0.1 : #ScaleUptime#

[UptimeScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleUptime# > 1.0 ? #ScaleUptime# - 0.1 : #ScaleUptime#

;------------------------------------------------------------------------------
; Meters

[UptimeScale_Text]
Meter=String
MeasureName=UptimeScale_MeasureScale
StringAlign=Right
X=([SkinSizing:W]-10)
Y=0r
W=42
H=20
AntiAlias=1
FontColor=#TextColor#
FontSize=14
Text=%1x
NumOfDecimals=1

[UptimeScale_MeterUptimeBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=UptimeScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleUptime [UptimeScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Uptime]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleUptime [UptimeScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Uptime]
DynamicVariables=1

[UptimeScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.0" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.1" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.2" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.3" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.4" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.5" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.6" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.7" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.8" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "1.9" "#@#variables.var"][!RefreshGroup Uptime]

[UptimeScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[UptimeScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleUptime "2.0" "#@#variables.var"][!RefreshGroup Uptime]
