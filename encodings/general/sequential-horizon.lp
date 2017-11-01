#const horizon = 1.

time(0..horizon).

consider(Y,V,horizon) :- derivedVariable(Y), contains(Y,V),
                         goal(Y,V).
consider(Y,V,T)       :- derivedVariable(Y), contains(Y,V),
                         precondition(E,Y,V), evaluate(E,T).
consider(Y,V,T)       :- derivedVariable(Y), contains(Y,V),
                         precondition(P,F,Y,V), evaluate(P,F,T).
consider(Y,T)         :- consider(Y,V,T).

evaluate(P,F,E,T) :- derivedPredicate(P,F), contains(Y,V),
                     postcondition(P,F,E,Y,V), consider(Y,T).
evaluate(P,F,T)   :- evaluate(P,F,E,T).
evaluate(E,T)     :- evaluate(P,F,E,T).
