# miniRegexParser
course in programming language theory.

And as the title says it's a small version of a regex parser.

## BNF
Expr => Concat | Brackets | Repeat | Or

Or => Concat + Concat | Repeat + concat

Brackets => (Expr)

Concat => Id | Id-Concat

Repeat => Concat*

Id is a charactor/number

## No tributes accepted
This is a school assement,
there for I do not acceept tributes.

## Not supported
Brackets within Brackets.

Brackets after Brackets - might be fixed later, this is cuz member function makeTokens() in the regex.
