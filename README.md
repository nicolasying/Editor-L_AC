Songsheng Ying, 5130369019, Oct 19, 2016

This is the final report for the program Editor L_AC developped on Qt, by Songsheng YING.
It is a comparison of the implementation and the first conception report.
# Editor L_AC
## 1.	introduction

A code editor customized for L_AC, a Fortran-like programming language invented by Alain Chillès. 

The build on [Windows x86](http://nicolasying.github.io/Editor-L_AC_win32.zip) and [macOS](http://nicolasying.github.io/Editor-L_AC_mac.zip) could be downloaded on clicking the link.

The source code could be found on [github](https://github.com/nicolasying/Editor-L_AC).

The interface is designed and presented using QtQuick, written in QML, which requires the hosting system machine's support for OpenGL.

This editor supports:

### A.	Code coloring (implemented)

i.	Based on lexical analysis <strike>and syntax analysis</strike>

+ Lexical analysis is implemented using the class `customizedSyntaxHighligher` inheriting `QSyntaxHighlighter`.
+ Syntax analysis is not implemented due to the shortage of time.

ii.	Highlights reserved words <strike>and user-defined functions</strike>.
+ It highlights not only the reserved words, but also applies different colors on strings and comments.
+ Coloring rules are written in JSON files, so the program is very extensible for support for new languages.
+ JSON file parsing uses the packets `QJsonDocument`, `QJsonObject`, `QJsonArray` and `QJsonValue`.

### <strike>B.	Code snippets

i.	Allowing a quick insertion of common programming code lines
ii.	Supporting quick replacement method for placeholder texts

### C.	An entrance to code compilation and interpretation
</strike>

+ I did reserve a button for the link to the compilation executive.
+ Although the compilation program is still under construction, which would be available by the end of W15.
+ The button now points to the github page of the project.

### D.	Customizable interface, code style <strike>and coloring scheme</strike>

+ Since the interface control is implemented using QtQuick in QML, the interface control details are implemented in mail.qml file.
+ Code style are controled by language JSON files. 
+ The coloring scheme is controled a style configuration file: *qtquickcontrols2.conf*, in which I implemented only a Material Design Style featuring a green color.

### E.	Supports more programming language by downloading more configurations

+ The configuration files are available [online](http://nicolasying.github.io/lac_language.json) for download.
+ For the time being here are two files composed. [L_AC](http://nicolasying.github.io/lac_language.json) and [C](http://nicolasying.github.io/c_language.json).
+ If you pay attention to the URL, you could spot the naming machanisme for different languages, which is implemented also in the Editor program to find new language files. Namely in *universalheader.h*

## 2.	Socket implementation
The program uses TCP connection to download more configuration files from a specific server using HTTP protocol.

More precisely, it uses the class `langFileFetcher` in *networkgetlangfile.h* using `QNetworkAccessManager`.

+ It uses asynchronous connection, namely separating the object calling for request for the file and the object that is actually fetching the file from the internet.
+ langFileFetcher is a handler for the QNetworkAccessManager, it deals with network connection, file storage and signal receiving and emission.
+ langFileFetcher waits for the signal from QNetworkAccessManager for the download compeletion signal.
+ The slot `saveFile()` was connected in several versions before, now it acts only as a member function.
+ The langFileFetcher emits signal for the `syntaxHighlighterHandler` in *highlighterhandler.h*, in order to construct a new `customizedSyntaxHighligher` using the freshly downloaded language coloring file.

## 3.	Class hierarchy 
<strike>Text : for all text displayed on editor
	Normal code,
	Reserved words,
	User defined functions,
	Comments,
Messages: for text displayed in the message window below the editor
	Warning/Error,
	Informational,
    </strike>
+ Since the program is implemented in QML, in which the items are placed hierarchically, the original design for class is more or less useless.
+ The new class hierarchy is presented in

`class DocumentHandler : public QObject`
who is responsible for opening and saving the file.

It should remark that the `DocumentHandler` isn't yet aware of file modification. Thus all files opened in the editor should be saved using *SaveAs* on overwriting the original file (not yet tested).

The difficulty on implementing this class is on its interaction with QML objects from C++, using the `Q_PROPERTY` phrases.

`class syntaxHilighterHandler : public QObject`
who is responsible for constructing and destroying the `customizedSyntaxHighligher`, using the correct coding language coloring scheme file.

`class langFileFetcher : public QObject`
who is responsible for fetching the language file from the web server, should there is no local copy of the language.

It also informes the `syntaxHilighterHandler` of the readiness of the file.

`class customizedSyntaxHighligher : public QSyntaxHighlighter`
who is responsible for coloring the code. Its coloring rules are parsed from the language file using a JSON parser.

At this stage, the `customizedSyntaxHighligher` isn't working at a promising efficency, and if the language is switched before it finishes coloring the whole document, it could lead to a program crash.

## 4. More information on the program.
+ The program has implemented a few shortcuts, including `Ctrl+X`, `Ctrl+C`, `Ctrl+V`, `Ctrl+O`, `Ctrl+Shift+S`, `Alt+F4` or `Cmd+Q` depending the host system.
+ `Ctrl+-` for zooming out, `Ctrl+=` for zooming in. 