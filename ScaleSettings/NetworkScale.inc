[Metadata]
Name=NetworkScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Network widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;------------------------------------------------------------------------------
; Measures

[NetworkScale_MeasureScale]
Measure=Calc
Formula=#ScaleNetwork#
MaxValue=2.0
MinValue=0.9

[NetworkScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleNetwork# < 2.0 ? #ScaleNetwork# + 0.1 : #ScaleNetwork#

[NetworkScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleNetwork# > 1.0 ? #ScaleNetwork# - 0.1 : #ScaleNetwork#

;------------------------------------------------------------------------------
; Meters

[NetworkScale_Text]
Meter=String
MeasureName=NetworkScale_MeasureScale
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

[NetworkScale_MeterNetworkBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=NetworkScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleNetwork [NetworkScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Network]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleNetwork [NetworkScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Network]
DynamicVariables=1

[NetworkScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.0" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.1" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.2" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.3" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.4" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.5" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.6" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.7" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.8" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "1.9" "#@#variables.var"][!RefreshGroup Network]

[NetworkScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[NetworkScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleNetwork "2.0" "#@#variables.var"][!RefreshGroup Network]
