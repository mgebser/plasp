%---------------------------------------
% domain
%---------------------------------------

% utils
boolean(true).
boolean(false).

% types
type(type("passenger")).
inherits(type("passenger"), type("object")).
type(type("object")).
type(type("going_up")).
inherits(type("going_up"), type("passenger")).
type(type("going_down")).
inherits(type("going_down"), type("passenger")).
type(type("vip")).
inherits(type("vip"), type("passenger")).
type(type("going_nonstop")).
inherits(type("going_nonstop"), type("passenger")).
type(type("attendant")).
inherits(type("attendant"), type("passenger")).
type(type("never_alone")).
inherits(type("never_alone"), type("passenger")).
type(type("conflict_a")).
inherits(type("conflict_a"), type("passenger")).
type(type("conflict_b")).
inherits(type("conflict_b"), type("passenger")).
type(type("floor")).
inherits(type("floor"), type("object")).

has(X, type(T2)) :- has(X, type(T1)), inherits(type(T1), type(T2)).

% variables
variable(variable(("origin", Person, Floor))) :- has(Person, type("passenger")), has(Floor, type("floor")).
variable(variable(("destin", Person, Floor))) :- has(Person, type("passenger")), has(Floor, type("floor")).
variable(variable(("no-access", Person, Floor))) :- has(Person, type("passenger")), has(Floor, type("floor")).
variable(variable(("above", Floor1, Floor2))) :- has(Floor1, type("floor")), has(Floor2, type("floor")).
variable(variable(("boarded", Person))) :- has(Person, type("passenger")).
variable(variable(("served", Person))) :- has(Person, type("passenger")).
variable(variable(("lift-at", Floor))) :- has(Floor, type("floor")).

contains(X, value(X, B)) :- variable(X), boolean(B).

% derived predicates
derivedVariable(derivedVariable(("derived-predicate-1", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-2", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-3", P, F))) :- has(P, type("conflict_a")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-4", P, F))) :- has(P, type("conflict_a")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-5", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-6", Q, F))) :- has(Q, type("conflict_b")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-7", Q, F))) :- has(Q, type("conflict_b")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-8", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-9", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-10", P, F))) :- has(P, type("conflict_b")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-11", P, F))) :- has(P, type("conflict_b")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-12", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-13", Q, F))) :- has(Q, type("conflict_a")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-14", Q, F))) :- has(Q, type("conflict_a")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-15", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-16", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-17", P, F))) :- has(P, type("never_alone")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-18", P, F))) :- has(P, type("never_alone")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-19", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-20", Q, F))) :- has(Q, type("attendant")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-21", Q, F))) :- has(Q, type("attendant")), has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-22", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-23", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable("derived-predicate-24")).
derivedVariable(derivedVariable(("derived-predicate-25", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable(("derived-predicate-26", F))) :- has(F, type("floor")).
derivedVariable(derivedVariable("derived-predicate-27")).
derivedVariable(derivedVariable("derived-predicate-28")).

contains(X, value(X, B)) :- derivedVariable(X), boolean(B).

derivedPredicate(derivedPredicate(("derived-predicate-1", F)), type(or)) :- has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-1", F)), type(or), derivedVariable(("derived-predicate-2", F)), value(derivedVariable(("derived-predicate-2", F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-1", F)), type(or)).
precondition(derivedPredicate(("derived-predicate-1", F)), type(or), derivedVariable(("derived-predicate-5", F)), value(derivedVariable(("derived-predicate-5", F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-1", F)), type(or)).
postcondition(derivedPredicate(("derived-predicate-1", F)), type(or), effect(unconditional), derivedVariable(("derived-predicate-1", F)), value(derivedVariable(("derived-predicate-1", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-1", F)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-2", F, P)), type(or)) :- has(F, type("floor")), has(P, type("conflict_a")).
precondition(derivedPredicate(("derived-predicate-2", F, P)), type(or), derivedVariable(("derived-predicate-3", P, F)), value(derivedVariable(("derived-predicate-3", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-2", F, P)), type(or)).
precondition(derivedPredicate(("derived-predicate-2", F, P)), type(or), derivedVariable(("derived-predicate-4", P, F)), value(derivedVariable(("derived-predicate-4", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-2", F, P)), type(or)).
postcondition(derivedPredicate(("derived-predicate-2", F, P)), type(or), effect(unconditional), derivedVariable(("derived-predicate-2", F)), value(derivedVariable(("derived-predicate-2", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-2", F, P)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-3", P, F)), type(and)) :- has(P, type("conflict_a")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-3", P, F)), type(and), variable(("served", P)), value(variable(("served", P)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-3", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-3", P, F)), type(and), variable(("origin", P, F)), value(variable(("origin", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-3", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-3", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-3", P, F)), value(derivedVariable(("derived-predicate-3", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-3", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-4", P, F)), type(and)) :- has(P, type("conflict_a")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-4", P, F)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-4", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-4", P, F)), type(and), variable(("destin", P, F)), value(variable(("destin", P, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-4", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-4", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-4", P, F)), value(derivedVariable(("derived-predicate-4", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-4", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-5", F, Q)), type(or)) :- has(F, type("floor")), has(Q, type("conflict_b")).
precondition(derivedPredicate(("derived-predicate-5", F, Q)), type(or), derivedVariable(("derived-predicate-6", Q, F)), value(derivedVariable(("derived-predicate-6", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-5", F, Q)), type(or)).
precondition(derivedPredicate(("derived-predicate-5", F, Q)), type(or), derivedVariable(("derived-predicate-7", Q, F)), value(derivedVariable(("derived-predicate-7", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-5", F, Q)), type(or)).
postcondition(derivedPredicate(("derived-predicate-5", F, Q)), type(or), effect(unconditional), derivedVariable(("derived-predicate-5", F)), value(derivedVariable(("derived-predicate-5", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-5", F, Q)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-6", Q, F)), type(and)) :- has(Q, type("conflict_b")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-6", Q, F)), type(and), variable(("destin", Q, F)), value(variable(("destin", Q, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-6", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-6", Q, F)), type(and), variable(("boarded", Q)), value(variable(("boarded", Q)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-6", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-6", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-6", Q, F)), value(derivedVariable(("derived-predicate-6", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-6", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-7", Q, F)), type(and)) :- has(Q, type("conflict_b")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-7", Q, F)), type(and), variable(("served", Q)), value(variable(("served", Q)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-7", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-7", Q, F)), type(and), variable(("origin", Q, F)), value(variable(("origin", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-7", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-7", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-7", Q, F)), value(derivedVariable(("derived-predicate-7", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-7", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-8", F)), type(or)) :- has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-8", F)), type(or), derivedVariable(("derived-predicate-9", F)), value(derivedVariable(("derived-predicate-9", F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-8", F)), type(or)).
precondition(derivedPredicate(("derived-predicate-8", F)), type(or), derivedVariable(("derived-predicate-12", F)), value(derivedVariable(("derived-predicate-12", F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-8", F)), type(or)).
postcondition(derivedPredicate(("derived-predicate-8", F)), type(or), effect(unconditional), derivedVariable(("derived-predicate-8", F)), value(derivedVariable(("derived-predicate-8", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-8", F)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-9", F, P)), type(or)) :- has(F, type("floor")), has(P, type("conflict_b")).
precondition(derivedPredicate(("derived-predicate-9", F, P)), type(or), derivedVariable(("derived-predicate-10", P, F)), value(derivedVariable(("derived-predicate-10", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-9", F, P)), type(or)).
precondition(derivedPredicate(("derived-predicate-9", F, P)), type(or), derivedVariable(("derived-predicate-11", P, F)), value(derivedVariable(("derived-predicate-11", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-9", F, P)), type(or)).
postcondition(derivedPredicate(("derived-predicate-9", F, P)), type(or), effect(unconditional), derivedVariable(("derived-predicate-9", F)), value(derivedVariable(("derived-predicate-9", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-9", F, P)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-10", P, F)), type(and)) :- has(P, type("conflict_b")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-10", P, F)), type(and), variable(("served", P)), value(variable(("served", P)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-10", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-10", P, F)), type(and), variable(("origin", P, F)), value(variable(("origin", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-10", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-10", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-10", P, F)), value(derivedVariable(("derived-predicate-10", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-10", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-11", P, F)), type(and)) :- has(P, type("conflict_b")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-11", P, F)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-11", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-11", P, F)), type(and), variable(("destin", P, F)), value(variable(("destin", P, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-11", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-11", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-11", P, F)), value(derivedVariable(("derived-predicate-11", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-11", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-12", F, Q)), type(or)) :- has(F, type("floor")), has(Q, type("conflict_a")).
precondition(derivedPredicate(("derived-predicate-12", F, Q)), type(or), derivedVariable(("derived-predicate-13", Q, F)), value(derivedVariable(("derived-predicate-13", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-12", F, Q)), type(or)).
precondition(derivedPredicate(("derived-predicate-12", F, Q)), type(or), derivedVariable(("derived-predicate-14", Q, F)), value(derivedVariable(("derived-predicate-14", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-12", F, Q)), type(or)).
postcondition(derivedPredicate(("derived-predicate-12", F, Q)), type(or), effect(unconditional), derivedVariable(("derived-predicate-12", F)), value(derivedVariable(("derived-predicate-12", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-12", F, Q)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-13", Q, F)), type(and)) :- has(Q, type("conflict_a")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-13", Q, F)), type(and), variable(("destin", Q, F)), value(variable(("destin", Q, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-13", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-13", Q, F)), type(and), variable(("boarded", Q)), value(variable(("boarded", Q)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-13", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-13", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-13", Q, F)), value(derivedVariable(("derived-predicate-13", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-13", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-14", Q, F)), type(and)) :- has(Q, type("conflict_a")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-14", Q, F)), type(and), variable(("served", Q)), value(variable(("served", Q)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-14", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-14", Q, F)), type(and), variable(("origin", Q, F)), value(variable(("origin", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-14", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-14", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-14", Q, F)), value(derivedVariable(("derived-predicate-14", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-14", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-15", F)), type(or)) :- has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-15", F)), type(or), derivedVariable(("derived-predicate-16", F)), value(derivedVariable(("derived-predicate-16", F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-15", F)), type(or)).
precondition(derivedPredicate(("derived-predicate-15", F)), type(or), derivedVariable(("derived-predicate-19", F)), value(derivedVariable(("derived-predicate-19", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-15", F)), type(or)).
postcondition(derivedPredicate(("derived-predicate-15", F)), type(or), effect(unconditional), derivedVariable(("derived-predicate-15", F)), value(derivedVariable(("derived-predicate-15", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-15", F)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-16", F, P)), type(or)) :- has(F, type("floor")), has(P, type("never_alone")).
precondition(derivedPredicate(("derived-predicate-16", F, P)), type(or), derivedVariable(("derived-predicate-17", P, F)), value(derivedVariable(("derived-predicate-17", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-16", F, P)), type(or)).
precondition(derivedPredicate(("derived-predicate-16", F, P)), type(or), derivedVariable(("derived-predicate-18", P, F)), value(derivedVariable(("derived-predicate-18", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-16", F, P)), type(or)).
postcondition(derivedPredicate(("derived-predicate-16", F, P)), type(or), effect(unconditional), derivedVariable(("derived-predicate-16", F)), value(derivedVariable(("derived-predicate-16", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-16", F, P)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-17", P, F)), type(and)) :- has(P, type("never_alone")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-17", P, F)), type(and), variable(("origin", P, F)), value(variable(("origin", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-17", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-17", P, F)), type(and), variable(("served", P)), value(variable(("served", P)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-17", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-17", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-17", P, F)), value(derivedVariable(("derived-predicate-17", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-17", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-18", P, F)), type(and)) :- has(P, type("never_alone")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-18", P, F)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-18", P, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-18", P, F)), type(and), variable(("destin", P, F)), value(variable(("destin", P, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-18", P, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-18", P, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-18", P, F)), value(derivedVariable(("derived-predicate-18", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-18", P, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-19", F, Q)), type(or)) :- has(F, type("floor")), has(Q, type("attendant")).
precondition(derivedPredicate(("derived-predicate-19", F, Q)), type(or), derivedVariable(("derived-predicate-20", Q, F)), value(derivedVariable(("derived-predicate-20", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-19", F, Q)), type(or)).
precondition(derivedPredicate(("derived-predicate-19", F, Q)), type(or), derivedVariable(("derived-predicate-21", Q, F)), value(derivedVariable(("derived-predicate-21", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-19", F, Q)), type(or)).
postcondition(derivedPredicate(("derived-predicate-19", F, Q)), type(or), effect(unconditional), derivedVariable(("derived-predicate-19", F)), value(derivedVariable(("derived-predicate-19", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-19", F, Q)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-20", Q, F)), type(and)) :- has(Q, type("attendant")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-20", Q, F)), type(and), variable(("boarded", Q)), value(variable(("boarded", Q)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-20", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-20", Q, F)), type(and), variable(("destin", Q, F)), value(variable(("destin", Q, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-20", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-20", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-20", Q, F)), value(derivedVariable(("derived-predicate-20", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-20", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-21", Q, F)), type(and)) :- has(Q, type("attendant")), has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-21", Q, F)), type(and), variable(("served", Q)), value(variable(("served", Q)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-21", Q, F)), type(and)).
precondition(derivedPredicate(("derived-predicate-21", Q, F)), type(and), variable(("origin", Q, F)), value(variable(("origin", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-21", Q, F)), type(and)).
postcondition(derivedPredicate(("derived-predicate-21", Q, F)), type(and), effect(unconditional), derivedVariable(("derived-predicate-21", Q, F)), value(derivedVariable(("derived-predicate-21", Q, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-21", Q, F)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-22", F, P)), type(and)) :- has(F, type("floor")), has(P, type("going_nonstop")).
precondition(derivedPredicate(("derived-predicate-22", F, P)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-22", F, P)), type(and)).
precondition(derivedPredicate(("derived-predicate-22", F, P)), type(and), variable(("destin", P, F)), value(variable(("destin", P, F)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-22", F, P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-22", F, P)), type(and), effect(unconditional), derivedVariable(("derived-predicate-22", F)), value(derivedVariable(("derived-predicate-22", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-22", F, P)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-23", F)), type(or)) :- has(F, type("floor")).
precondition(derivedPredicate(("derived-predicate-23", F)), type(or), derivedVariable("derived-predicate-24"), value(derivedVariable("derived-predicate-24"), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-23", F)), type(or)).
precondition(derivedPredicate(("derived-predicate-23", F)), type(or), derivedVariable(("derived-predicate-25", F)), value(derivedVariable(("derived-predicate-25", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-23", F)), type(or)).
postcondition(derivedPredicate(("derived-predicate-23", F)), type(or), effect(unconditional), derivedVariable(("derived-predicate-23", F)), value(derivedVariable(("derived-predicate-23", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-23", F)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-24", P)), type(and)) :- has(P, type("vip")).
precondition(derivedPredicate(("derived-predicate-24", P)), type(and), variable(("served", P)), value(variable(("served", P)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-24", P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-24", P)), type(and), effect(unconditional), derivedVariable("derived-predicate-24"), value(derivedVariable("derived-predicate-24"), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-24", P)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-25", F, P)), type(or)) :- has(F, type("floor")), has(P, type("vip")).
precondition(derivedPredicate(("derived-predicate-25", F, P)), type(or), variable(("origin", P, F)), value(variable(("origin", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-25", F, P)), type(or)).
precondition(derivedPredicate(("derived-predicate-25", F, P)), type(or), variable(("destin", P, F)), value(variable(("destin", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-25", F, P)), type(or)).
postcondition(derivedPredicate(("derived-predicate-25", F, P)), type(or), effect(unconditional), derivedVariable(("derived-predicate-25", F)), value(derivedVariable(("derived-predicate-25", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-25", F, P)), type(or)).

derivedPredicate(derivedPredicate(("derived-predicate-26", F, P)), type(and)) :- has(F, type("floor")), has(P, type("passenger")).
precondition(derivedPredicate(("derived-predicate-26", F, P)), type(and), variable(("no-access", P, F)), value(variable(("no-access", P, F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-26", F, P)), type(and)).
precondition(derivedPredicate(("derived-predicate-26", F, P)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-26", F, P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-26", F, P)), type(and), effect(unconditional), derivedVariable(("derived-predicate-26", F)), value(derivedVariable(("derived-predicate-26", F)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-26", F, P)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-27", P)), type(and)) :- has(P, type("going_down")).
precondition(derivedPredicate(("derived-predicate-27", P)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-27", P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-27", P)), type(and), effect(unconditional), derivedVariable("derived-predicate-27"), value(derivedVariable("derived-predicate-27"), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-27", P)), type(and)).

derivedPredicate(derivedPredicate(("derived-predicate-28", P)), type(and)) :- has(P, type("going_up")).
precondition(derivedPredicate(("derived-predicate-28", P)), type(and), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-28", P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-28", P)), type(and), effect(unconditional), derivedVariable("derived-predicate-28"), value(derivedVariable("derived-predicate-28"), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-28", P)), type(and)).

% actions
action(action(("stop", F))) :- has(F, type("floor")).
precondition(action(("stop", F)), variable(("lift-at", F)), value(variable(("lift-at", F)), true)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-1", F)), value(derivedVariable(("derived-predicate-1", F)), true)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-8", F)), value(derivedVariable(("derived-predicate-8", F)), true)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-15", F)), value(derivedVariable(("derived-predicate-15", F)), true)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-22", F)), value(derivedVariable(("derived-predicate-22", F)), false)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-23", F)), value(derivedVariable(("derived-predicate-23", F)), true)) :- action(action(("stop", F))).
precondition(action(("stop", F)), derivedVariable(("derived-predicate-26", F)), value(derivedVariable(("derived-predicate-26", F)), false)) :- action(action(("stop", F))).
precondition(effect(1), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- action(action(("stop", F))), has(P, type("passenger")).
precondition(effect(1), variable(("destin", P, F)), value(variable(("destin", P, F)), true)) :- action(action(("stop", F))), has(P, type("passenger")).
postcondition(action(("stop", F)), effect(1), variable(("boarded", P)), value(variable(("boarded", P)), false)) :- action(action(("stop", F))), has(P, type("passenger")).
postcondition(action(("stop", F)), effect(1), variable(("served", P)), value(variable(("served", P)), true)) :- action(action(("stop", F))), has(P, type("passenger")).
precondition(effect(2), variable(("origin", P, F)), value(variable(("origin", P, F)), true)) :- action(action(("stop", F))), has(P, type("passenger")).
precondition(effect(2), variable(("served", P)), value(variable(("served", P)), false)) :- action(action(("stop", F))), has(P, type("passenger")).
postcondition(action(("stop", F)), effect(2), variable(("boarded", P)), value(variable(("boarded", P)), true)) :- action(action(("stop", F))), has(P, type("passenger")).

action(action(("up", F1, F2))) :- has(F1, type("floor")), has(F2, type("floor")).
precondition(action(("up", F1, F2)), variable(("lift-at", F1)), value(variable(("lift-at", F1)), true)) :- action(action(("up", F1, F2))).
precondition(action(("up", F1, F2)), variable(("above", F1, F2)), value(variable(("above", F1, F2)), true)) :- action(action(("up", F1, F2))).
precondition(action(("up", F1, F2)), derivedVariable("derived-predicate-27"), value(derivedVariable("derived-predicate-27"), false)) :- action(action(("up", F1, F2))).
postcondition(action(("up", F1, F2)), effect(unconditional), variable(("lift-at", F2)), value(variable(("lift-at", F2)), true)) :- action(action(("up", F1, F2))).
postcondition(action(("up", F1, F2)), effect(unconditional), variable(("lift-at", F1)), value(variable(("lift-at", F1)), false)) :- action(action(("up", F1, F2))).

action(action(("down", F1, F2))) :- has(F1, type("floor")), has(F2, type("floor")).
precondition(action(("down", F1, F2)), variable(("lift-at", F1)), value(variable(("lift-at", F1)), true)) :- action(action(("down", F1, F2))).
precondition(action(("down", F1, F2)), variable(("above", F2, F1)), value(variable(("above", F2, F1)), true)) :- action(action(("down", F1, F2))).
precondition(action(("down", F1, F2)), derivedVariable("derived-predicate-28"), value(derivedVariable("derived-predicate-28"), false)) :- action(action(("down", F1, F2))).
postcondition(action(("down", F1, F2)), effect(unconditional), variable(("lift-at", F2)), value(variable(("lift-at", F2)), true)) :- action(action(("down", F1, F2))).
postcondition(action(("down", F1, F2)), effect(unconditional), variable(("lift-at", F1)), value(variable(("lift-at", F1)), false)) :- action(action(("down", F1, F2))).

%---------------------------------------
% problem
%---------------------------------------

% objects
constant(constant("p0")).
has(constant("p0"), type("passenger")).

constant(constant("f0")).
has(constant("f0"), type("floor")).

constant(constant("f1")).
has(constant("f1"), type("floor")).

% initial state
initialState(variable(("above", constant("f0"), constant("f1"))), value(variable(("above", constant("f0"), constant("f1"))), true)).
initialState(variable(("origin", constant("p0"), constant("f1"))), value(variable(("origin", constant("p0"), constant("f1"))), true)).
initialState(variable(("destin", constant("p0"), constant("f0"))), value(variable(("destin", constant("p0"), constant("f0"))), true)).
initialState(variable(("lift-at", constant("f0"))), value(variable(("lift-at", constant("f0"))), true)).

initialState(X, value(X, false)) :- variable(X), not initialState(X, value(X, true)).

% derived predicates
derivedVariable(derivedVariable("derived-predicate-29")).

contains(X, value(X, B)) :- derivedVariable(X), boolean(B).

derivedPredicate(derivedPredicate(("derived-predicate-29", P)), type(and)) :- has(P, type("passenger")).
precondition(derivedPredicate(("derived-predicate-29", P)), type(and), variable(("served", P)), value(variable(("served", P)), false)) :- derivedPredicate(derivedPredicate(("derived-predicate-29", P)), type(and)).
postcondition(derivedPredicate(("derived-predicate-29", P)), type(and), effect(unconditional), derivedVariable("derived-predicate-29"), value(derivedVariable("derived-predicate-29"), true)) :- derivedPredicate(derivedPredicate(("derived-predicate-29", P)), type(and)).

% goal
goal(derivedVariable("derived-predicate-29"), value(derivedVariable("derived-predicate-29"), false)).
