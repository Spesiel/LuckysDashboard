[Rainmeter]
Update=1000
BackgroundMode=2
SolidColor=#BackgroundColor#
BackgroundMargins=0,0,0,0

;------------------------------------------------------------------------------
; Custom context menu to access different configuration options 

ContextTitle=Configure Scale settings
ContextAction=[!ActivateConfig "#RootConfig#\ScaleSettings" "ScaleSettings.ini"]
ContextTitle2=Configure Themes
ContextAction2=[!ActivateConfig "#RootConfig#\Themes" "Themes.ini"]
ContextTitle3=-
ContextTitle4=Refresh All
ContextAction4=[!RefreshApp]

LeftMouseDoubleClickAction=!SkinCustomMenu

[Metadata]
Name=GlobalSettings
Author=Lucky Penny
Information=Default values for every component
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

[VarFileInit]
Measure=Script
ScriptFile=#@#\VarFileInit.lua

@includeVariables=variables.var

[Variables]

;------------------------------------------------------------------------------
; Colors

ColorClear=0,0,0,0

;------------------------------------------------------------------------------
; Clocks-specific constants

; Transformation Matrix for ScaleClock
Scaling=#ScaleClock#;0;0;#ScaleClock#;#ScaleClock#;#ScaleClock#


;------------------------------------------------------------------------------
; Measures Styling

[BarStyle]
BarOrientation=Horizontal
BarColor=#ForegroundColor#
SolidColor=#ForegroundColorDimMin#

;------------------------------------------------------------------------------
; Text Styling

[TextStyle]
StringStyle=Bold
StringEffect=Shadow
FontEffectColor=0,0,0,20
FontColor=#ForegroundColor#
FontFace=Trebuchet MS
FontSize=12
AntiAlias=1
ClipString=1

;------------------------------------------------------------------------------
;------------------------------------------------------------------------------
; Clocks-specific constants

; Skin sizing

[SkinSizing]
Meter=Image
X=0
Y=0
W=(125*#ScaleClock#)
H=(([MeterTimeSecondsBar:Y]+1+[MeterTimeSecondsBar:H]+5)*#ScaleClock#)
DynamicVariables=1
UpdateDivider=-1
