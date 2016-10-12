[Metadata]
Name=DateScale
Author=Lucky Penny
Information=Display the bar used for manipulating the scale of the Date widget
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

;------------------------------------------------------------------------------
; Measures

[DateScale_MeasureScale]
Measure=Calc
Formula=#ScaleDate#
MaxValue=2.0
MinValue=0.9

[DateScale_MeasureScaleUp]
Measure=Calc
Formula=#ScaleDate# < 2.0 ? #ScaleDate# + 0.1 : #ScaleDate#

[DateScale_MeasureScaleDown]
Measure=Calc
Formula=#ScaleDate# > 1.0 ? #ScaleDate# - 0.1 : #ScaleDate#

;------------------------------------------------------------------------------
; Meters

[DateScale_Text]
Meter=String
MeasureName=DateScale_MeasureScale
StringAlign=Right
X=390
Y=0r
W=42
H=20
AntiAlias=1
FontColor=#TextColor#
FontSize=14
Text=%1x
NumOfDecimals=1

[DateScale_MeterDateBar]
Meter=Bar
MeterStyle=BarStyle
MeasureName=DateScale_MeasureScale
X=-190r
Y=0r
W=143
H=20
MouseScrollUpAction=[!WriteKeyValue Variables ScaleDate [DateScale_MeasureScaleUp] "#@#variables.var"][!RefreshGroup Date]
MouseScrollDownAction=[!WriteKeyValue Variables ScaleDate [DateScale_MeasureScaleDown] "#@#variables.var"][!RefreshGroup Date]
DynamicVariables=1

[DateScale_MeterSet1.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.0" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.0line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.1]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.1" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.1line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.2]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.2" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.2line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.3]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.3" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.3line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.4]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.4" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.4line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.5]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.5" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.5line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.6]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.6" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.6line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.7]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.7" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.7line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.8]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.8" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.8line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet1.9]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "1.9" "#@#variables.var"][!RefreshGroup Date]

[DateScale_MeterSet1.9line]
Meter=Image
X=13r
Y=0r
W=1
H=20
SolidColor=#BackgroundColor#

[DateScale_MeterSet2.0]
Meter=Image
X=0r
Y=0r
W=13
H=20
AntiAlias=1
LeftMouseUpAction=[!WriteKeyValue Variables ScaleDate "2.0" "#@#variables.var"][!RefreshGroup Date]
