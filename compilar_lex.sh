#!/bin/bash

#################################################
# Generar el c
lex tokens.l

# Generar el ejectuable
gcc lex.yy.c -lfl -o analizador-lexico

##################################################