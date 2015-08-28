miniRegexParser
===============
course in programming language theory.

And as the title says it's a small version of a regex parser.

more deitials will come at a later time.

How to use
==========

id* is to find minmum id and possible infinty id.

id is either a number or letter that most be fond.

expr1+expr2  means to find either expr1 or expr2 (left most).

(expr) is used to search as it's own expresion.


BNF
===
Expr => Concat | Paren | Repeat | Or

Or => Expr + Expr

Parentes => (Expr)

Concat => Id | Id Concat | Expr Concat

Repeat => Id* | Parentes*  -- might change soon.

No tributes accepted
====================

This is a school assement and it's not done.
There for i do not acceept tributes til it's done.
