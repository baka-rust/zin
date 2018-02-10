grammar Zin;

// terminals
ID: [a-zA-Z_][a-zA-Z_0-9]* ;
INT: [0-9]+ ;
STRING: '"' ~["\\\r\n]+ '"' ;
BOOL: ('true' | 'false') ;
WS: ( '\t' | ' ' | '\r' | '\n' | '\u000C' )+ -> skip ;
COMMENT: '//' ~( '\r' | '\n' )* -> skip ;

// non-terminals
program           : statement* EOF;

statement         : expression ;

expression        : definition
                  | assignment
                  | invocation
                  | lambda
                  | function
                  | spread
                  | '(' expression ')'
                  | return_statement
                  | expression infix_operand expression
                  | prefix_operand expression
                  | atom
                  | name
                  ;

definition        : 'let' (ID | persisted_name) '=' expression ;

assignment        : name ('=' |'+=' | '-=' | '*=' | '/=') expression ;


invocation        : name '(' expression_list? ')' ;

lambda            : '(' argument_list? ')' '=>' (expression | block) ;

function          : 'let' (ID | persisted_name) ('(' argument_list? ')')? '=>' (expression | block);

block             : '(' expression* ')' ;

spread            : '**' expression ;

infix_operand     : '*' | '/' | '%' | '+' | '-'
                  | '>' | '<' | '>=' | '<=' | '!=' | '=='
                  | '&&' | '||'
                  ;

prefix_operand    : '-' | '!' ;

argument_list     : (ID | persisted_name) (',' (ID | persisted_name))* ;

expression_list   : expression (',' expression)* ;

return_statement  : 'return' expression ;

name              : ID
                  | name '.' name
                  ;

persisted_name    : ':' ID ;

atom              : INT
                  | STRING
                  | BOOL
                  ;
