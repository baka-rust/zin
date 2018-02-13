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
                  | if_statement
                  | return_statement
                  | expression infix_operand expression
                  | prefix_operand expression
                  | qualified_id
                  | literal
                  ;

definition        : 'let' persistable_id '=' expression ;

assignment        : qualified_id ('=' |'+=' | '-=' | '*=' | '/=') expression ;

invocation        : qualified_id '(' expression_list? ')' ;

expression_list   : expression (',' expression)* ;

lambda            : '(' argument_list? ')' '=>' (expression | block) ;

function          : 'let' persistable_id ('(' argument_list? ')')? '=>' (expression | block);

block             : '(' expression* ')' ;

argument_list     : persistable_id (',' persistable_id)* ;

spread            : '**' expression ;

return_statement  : 'return' expression ;

infix_operand     : op_mul_div_mod
                  | op_add_sub
                  | op_compare
                  | op_and
                  | op_or
                  ;

op_mul_div_mod    : '*' | '/' | '%' ;

op_add_sub        : '+' | '-' ;

op_compare        : '>' | '<' | '>=' | '<=' | '!=' | '==' ;

op_and            : '&&' ;

op_or             : '||' ;


prefix_operand    : '-' | '!' ;

qualified_id      : ID
                  | qualified_id '.' qualified_id
                  ;

persistable_id    : ID
                  | ':' ID ;

literal           : INT
                  | STRING
                  | BOOL
                  | list
                  ;

list              : '[' expression_list? ']' ;
