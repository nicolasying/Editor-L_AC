# Editor L_AC
## 1.	introduction

A code editor customized for L_AC, a Fortran-like programming language invented by Alain Chillès. This editor shall support:

A.	Code coloring

i.	Based on lexical analysis and syntax analysis

ii.	High lights reserved words and user-defined functions.

B.	Code snippets

i.	Allowing a quick insertion of common programming code lines

ii.	Supporting quick replacement method for placeholder texts

C.	An entrance to code compilation and interpretation

D.	Customizable interface, code style and coloring scheme

E.	Supports more programming language by downloading more configurations

## 2.	Socket implementation

The program uses TCP connection to download more configuration files from a specific server using HTTP protocol.

## 3.	Class hierarchy 

Text : for all text displayed on editor

	Normal code,
	
	Reserved words,
	
	User defined functions,
	
	Comments,
	
Messages: for text displayed in the message window below the editor

	Warning/Error,
	
	Informational,
