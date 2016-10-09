[Rainmeter]
Update=1000
BackgroundMode=2
SolidColor=#BackgroundColor#
BackgroundMargins=0,0,0,0

;------------------------------------------------------------------------------
; Custom context menu to access different configuration options 

ContextTitle=Configure settings
ContextAction=[!ActivateConfig "#RootConfig#\Settings" "Settings.ini"]
ContextTitle2=Themes
ContextAction2=[!ActivateConfig "#RootConfig#\Themes" "Themes.ini"]
ContextTitle3=------------------
ContextTitle4=Refresh All
ContextAction4=[!RefreshApp]

LeftMouseDoubleClickAction=!SkinCustomMenu

[Metadata]
Name=GlobalSettings
Author=Lucky Penny
Information=Default values for every component
License=Creative Commons BY-NC-SA 3.0
Version=0.0.1

@includeVariables=Variables.inc

[Variables]

;------------------------------------------------------------------------------
; Colors

ColorClear=0,0,0,0

;------------------------------------------------------------------------------
; Bar Styling

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
