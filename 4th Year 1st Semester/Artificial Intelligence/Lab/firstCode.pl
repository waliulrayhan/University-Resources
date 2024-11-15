hello_world :-
    write('Hello, World!').

goodbye :-
    write('Goodbye!').

greet :-
    write('What is your name? '),
    read(Name),
    write('What is your age? '),
    read(Age),
    format('Hello, ~w! You are ~w years old.', [Name, Age]).

% Addition and subtraction
add(X, Y, Result) :- Result is X + Y.
subtract(X, Y, Result) :- Result is X - Y.

% Factorial calculation
factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, SubResult),
    Result is N * SubResult.

% Square of a number
square(X, Result) :- Result is X * X.

% Fibonacci calculation
fibonacci(0, 0).
fibonacci(1, 1).
fibonacci(N, Result) :-
    N > 1,
    N1 is N - 1,
    N2 is N - 2,
    fibonacci(N1, R1),
    fibonacci(N2, R2),
    Result is R1 + R2.

%Check if a Number is Even or Odd
is_even(X) :-
    0 is X mod 2,
    write('Even').
is_even(X) :-
    1 is X mod 2,
    write('Odd').

%Determine if a number is positive, negative, or zero.
number_sign(X) :-
    X > 0, write('Positive').
number_sign(X) :-
    X < 0, write('Negative').
number_sign(0) :-
    write('Zero').

% Comparison Operators
is_greater(X, Y) :-
    X > Y,
    format('~w is greater than ~w', [X, Y]).
is_greater(X, Y) :-
    X =< Y,
    format('~w is not greater than ~w', [X, Y]).

% Leap year check
is_leap_year(Year) :-
    (Year mod 4 =:= 0, Year mod 100 =\= 0 ; Year mod 400 =:= 0),
    write(Year), write(' is a leap year').
is_leap_year(Year) :-
    \+ (Year mod 4 =:= 0, Year mod 100 =\= 0 ; Year mod 400 =:= 0),
    write(Year), write(' is not a leap year').

% Calculate the length of a list
list_length([], 0).
list_length([_|T], Len) :-
    list_length(T, Len1),
    Len is Len1 + 1.
%?- list_length([1, 2, 3, 4, 5], Length).

% Find the maximum element in a list
max_in_list([X], X).
max_in_list([H|T], Max) :-
    max_in_list(T, TempMax),
    Max is max(H, TempMax).
%?- max_in_list([10, 5, 8, 22, 15], Max).

% Rule to remove duplicates from a list
remove_duplicates([], []).  % An empty list has no duplicates.
remove_duplicates([H|T], Result) :-
    member(H, T),           % If H is a member of T, skip H.
    remove_duplicates(T, Result).
remove_duplicates([H|T], [H|Result]) :-
    \+ member(H, T),        % If H is not a member of T, keep H.
    remove_duplicates(T, Result).
%?- remove_duplicates([1, 2, 2, 3, 4, 4, 5], Result).


% Sum the elements of a list
sum_list([], 0).  % Base case: sum of an empty list is 0
sum_list([H|T], Sum) :-
    sum_list(T, Sum1),  % Recursive call to sum the tail
    Sum is H + Sum1.    % Correct logic to calculate the sum
%?- sum_list([1, 2, 3, 4], Sum).
% Expected output: Sum = 10.

%===============================================================
% Family Tree
% Family tree facts
male(john).
male(peter).
male(mike).
female(mary).
female(susan).
female(linda).

parent(john, peter).
parent(john, mary).
parent(mary, susan).
parent(peter, mike).
parent(linda, mike).

% Extended Facts for Grandparent, Aunt, and Uncle Relationships
parent(susan, alice). % New relationship
parent(john, david). % Another child of John to create uncle relationship

% Spouse Facts
spouse(john, linda).
spouse(peter, mary).


% Define relationships
father(F, C) :-
    male(F),
    parent(F, C).

mother(M, C) :-
    female(M),
    parent(M, C).

sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

% to Run
% Find all children of John
% ?- parent(john, Child).

% List all grandchildren of John
% ?- parent(john, Child), parent(Child, Grandchild).

% Find all siblings of Mary
% ?- sibling(mary, Sibling).

% Find all females with children
% ?- mother(Female, _).

% List all uncles
% ?- sibling(Uncle, Parent), male(Uncle).

% Grandparent Rule
grandparent(GP, GC) :-
    parent(GP, P),
    parent(P, GC).

% Aunt and Uncle Rules
uncle(U, N) :-
    male(U),
    sibling(U, P),
    parent(P, N).

aunt(A, N) :-
    female(A),
    sibling(A, P),
    parent(P, N).

children_of(Parent, Child) :-
    parent(Parent, Child).
% ?- children_of(john, Child).

% Great-grandparent Rule
great_grandparent(GGP, GGC) :-
    parent(GGP, GP),
    parent(GP, P),
    parent(P, GGC).
% ?- great_grandparent(john, GreatGrandChild).

% Cousin Rule
cousin(X, Y) :-
    parent(P1, X),
    parent(P2, Y),
    sibling(P1, P2),
    X \= Y.
% ?- cousin(susan, alice).

% Marital Relationship Rule
married(Person1, Person2) :-
    spouse(Person1, Person2);
    spouse(Person2, Person1).
% ?- married(john, linda).

% Rule to Check if Someone is a Parent Together
co_parents(Parent1, Parent2, Child) :-
    parent(Parent1, Child),
    parent(Parent2, Child),
    Parent1 \= Parent2.
% ?- co_parents(Parent1, Parent2, mike).


% Query Exercises:
%
% ?- uncle(Uncle, john).
%
% ?- sibling(mary, Sibling).
%
% Find all children of John: ?- parent(john, Child).
%
% List all grandchildren of John: ?- parent(john, Child), parent(Child,
% Grandchild).
%
% Find all siblings of Mary: ?- sibling(mary, Sibling).
%
% Who are the mothers in the family: ?- mother(Mother, _).
%
% List all uncles in the family: ?- sibling(Uncle, Parent), male(Uncle).
%
% Find all cousins of Mike: ?- parent(Parent1, Mike), sibling(Parent1,
% Parent2), parent(Parent2, Cousin), Cousin \= Mike.
%
% Who are the grandparents in the family: ?- parent(Parent, Person),
% parent(Parent, ParentOfParent), Person \= ParentOfParent.
%
% List all females who have children: ?- mother(Female, _).
%
% Find all siblings and their children: ?- sibling(X, Y), parent(X,
% Child), format('~w is a sibling of ~w and has child ~w.~n', [X, Y,
% Child]), fail.
%
% List all males in the family with their children: ?- male(Male),
% parent(Male, Child), format('~w has child ~w.~n', [Male, Child]), fail.

% ======================================================================
% Facts for basic gates
and_gate(0, 0, 0).
and_gate(0, 1, 0).
and_gate(1, 0, 0).
and_gate(1, 1, 1).
% ?- and_gate(0, 0, Output).
% Output = 0.

or_gate(0, 0, 0).
or_gate(0, 1, 1).
or_gate(1, 0, 1).
or_gate(1, 1, 1).
% ?- or_gate(0, 1, Output).
% Output = 1.


% Rule for NOT gate
not_gate(0, 1).
not_gate(1, 0).
% ?- not_gate(0, Output).
% Output = 1.


% XOR Gate
xor_gate(0, 0, 0).
xor_gate(0, 1, 1).
xor_gate(1, 0, 1).
xor_gate(1, 1, 0).
% ?- xor_gate(1, 0, Output).


% NOR Gate
nor_gate(0, 0, 1).
nor_gate(0, 1, 0).
nor_gate(1, 0, 0).
nor_gate(1, 1, 0).

% NAND Gate
nand_gate(0, 0, 1).
nand_gate(0, 1, 1).
nand_gate(1, 0, 1).
nand_gate(1, 1, 0).

% Half Adder
half_adder(A, B, Sum, Carry) :-
    xor_gate(A, B, Sum),
    and_gate(A, B, Carry).
% ?- half_adder(1, 1, Sum, Carry).

% Full Adder
full_adder(A, B, Cin, Sum, Cout) :-
    half_adder(A, B, Sum1, Carry1),
    half_adder(Sum1, Cin, Sum, Carry2),
    or_gate(Carry1, Carry2, Cout).
% ?- full_adder(1, 0, 1, Sum, Cout).


% 4-bit Adder
four_bit_adder([A3, A2, A1, A0], [B3, B2, B1, B0], [Cout, S3, S2, S1, S0]) :-
    full_adder(A0, B0, 0, S0, C1),
    full_adder(A1, B1, C1, S1, C2),
    full_adder(A2, B2, C2, S2, C3),
    full_adder(A3, B3, C3, S3, Cout).
% ?- four_bit_adder([1, 0, 1, 1], [0, 1, 0, 1], Result).


% 2-1 Mux
mux_2to1(Select, Input0, Input1, Output) :-
    (Select = 0 -> Output = Input0 ; Output = Input1).
% ?- mux_2to1(1, 0, 1, Output).

%==============================================================
% Define the available courses
course(cs101).
course(cs102).

course(math101).
course(math102).
course(eng101).
course(eng102).

% Define the available time slots
time_slot(monday, 9).
time_slot(monday, 11).
time_slot(tuesday, 9).
time_slot(tuesday, 11).
time_slot(wednesday, 9).
time_slot(wednesday, 11).
time_slot(thursday, 9).
time_slot(thursday, 11).
time_slot(friday, 9).
time_slot(friday, 11).

% Define the available instructors
instructor(john).
instructor(jane).
instructor(bob).

% Define the course schedule predicate
schedule(Course, Instructor, Day, Time) :-
    course(Course),
    instructor(Instructor),
    time_slot(Day, Time).
% ?- schedule(Course, Instructor, Day, Time).
% ?- schedule(cs101, john, monday, 9).

%=================================================================
% Define the available products
product(laptop, 1000).
product(desktop, 800).
product(printer, 200).
product(scanner, 150).

% Define the available customers
customer(john, 5000).
customer(jane, 3000).
customer(bob, 2000).

% Define the sales history
sale(john, laptop, 1).
sale(john, printer, 2).
sale(jane, desktop, 2).
sale(jane, scanner, 1).
sale(bob, laptop, 2).

% Define the price calculation predicate
price(Customer, Product, Quantity, Price) :-
    customer(Customer, Budget),
    product(Product, UnitPrice),
    Price is UnitPrice * Quantity,
    Price =< Budget.

% Define the sales report predicate
sales_report(Customer, Product, Quantity, Price) :-
    sale(Customer, Product, Quantity),
    price(Customer, Product, Quantity, Price).

% ?- price(john, laptop, 1, Price).
% ?- sales_report(Customer, Product, Quantity, Price).



%======================================================================
% Employee Scheduling
% Define the available employees
employee(john).
employee(jane).
employee(bob).
employee(sara).

% Define the available shifts
shift(morning).
shift(afternoon).
shift(evening).

% Define the available days
day(monday).
day(tuesday).
day(wednesday).
day(thursday).
day(friday).

% Define the employee availability
available(john, monday, morning).
available(john, tuesday, afternoon).
available(john, wednesday, evening).
available(john, thursday, morning).
available(john, friday, afternoon).

available(jane, monday, morning).
available(jane, tuesday, morning).
available(jane, wednesday, afternoon).
available(jane, thursday, evening).
available(jane, friday, morning).

available(bob, monday, afternoon).
available(bob, tuesday, evening).
available(bob, wednesday, morning).
available(bob, thursday, afternoon).
available(bob, friday, evening).

available(sara, monday, evening).
available(sara, tuesday, morning).
available(sara, wednesday, afternoon).
available(sara, thursday, evening).
available(sara, friday, morning).

% Define the work requirements
work(morning, 2).   % 2 employees needed in the morning
work(afternoon, 3). % 3 employees needed in the afternoon
work(evening, 2).   % 2 employees needed in the evening

% Define the schedule predicate
schedule(Employee, Day, Shift) :-
    employee(Employee),
    day(Day),
    shift(Shift),
    available(Employee, Day, Shift),
    findall(Shift, available(Employee, Day, Shift), Shifts),
    length(Shifts, ShiftCount),
    work(Shift, RequiredShifts),
    ShiftCount >= RequiredShifts.

% Define the schedule report predicate
schedule_report(Day) :-
    day(Day),
    write('--- Schedule for '), write(Day), writeln(' ---'),
    schedule(Employee, Day, Shift),
    write(Employee), write(' - '), write(Shift), writeln(' shift'),
    fail.
schedule_report(_).
% ?- schedule_report(monday).
% ?- schedule(john, Day, Shift).

%=====================================================================
% Music Recommendation System
% Define the available artists
artist(beatles).
artist(beyonce).
artist(johnny_cash).
artist(taylor_swift).
artist(ed_sheeran).
artist(rihanna).

% Define the available genres
genre(rock).
genre(pop).
genre(country).
genre(rap).

% Define the user preferences
like(john, beatles, rock).
like(john, ed_sheeran, pop).
like(john, taylor_swift, pop).

like(jane, beyonce, pop).
like(jane, rihanna, pop).
like(jane, johnny_cash, country).

like(jim, johnny_cash, country).
like(jim, ed_sheeran, pop).

like(sara, rihanna, pop).
like(sara, beyonce, pop).
like(sara, ed_sheeran, pop).

% Define the recommend predicate
recommend(User, Artist) :-
    like(User, _, Genre),
    artist(Artist),
    genre(Genre),
    like(User, Artist, Genre).

% Define the recommend report predicate
recommend_report(User) :-
    like(User, _, _),
    write('--- Recommendations for '), write(User), writeln(' ---'),
    recommend(User, Artist),
    write(Artist), writeln(' - recommended'),
    fail.
recommend_report(_).
% ?- recommend_report(john).
% ?- recommend(jane, Artist).

%=====================================================================
% Food Allergy Checker
% Define the food items
food(pizza).
food(soup).
food(salad).

% Define the ingredients for each food item
ingredient(pizza, dough).
ingredient(pizza, tomato_sauce).
ingredient(pizza, cheese).

ingredient(soup, broth).
ingredient(soup, vegetables).

ingredient(salad, lettuce).
ingredient(salad, tomatoes).

% Define allergens
allergen(milk).
allergen(wheat).
allergen(gluten).
allergen(shellfish).

% Check if a given meal is safe for a user with specific allergies
is_safe_to_eat(Meal, Allergies) :-
    findall(Ingredient, (
        ingredient(Meal, Ingredient),
        allergen(Allergy),
        allergic_to(Allergy, Allergies),
        \+ safe_for_allergic(Ingredient, Allergy)
    ), UnsafeIngredients),
    length(UnsafeIngredients, 0).

% Helper predicate to check if an allergy is in the list of allergies
allergic_to(Allergy, [Allergy|_]).
allergic_to(Allergy, [_|RestAllergies]) :- allergic_to(Allergy, RestAllergies).

% Helper predicate to check if an ingredient is safe for someone with an allergy
safe_for_allergic(Ingredient, Allergy) :-
    \+ allergen(Allergy) ;
    \+ ingredient_has_allergen(Ingredient, Allergy).

% Predicate to check if an ingredient contains an allergen
ingredient_has_allergen(Ingredient, Allergy) :-
    ingredient(Ingredient, Ingredients),
    allergen(Allergy),
    member(Allergy, Ingredients).

% ?- is_safe_to_eat(pizza, [milk, gluten]).
% ?- is_safe_to_eat(salad, [milk, wheat]).

%======================================================================
% Travel Planner
% Define destinations and their corresponding costs
destination(paris, 1000).
destination(london, 1200).
destination(tokyo, 1500).
destination(new_york, 1300).
destination(los_angeles, 1100).
destination(sydney, 1400).

% Define activities and their corresponding costs
activity(sightseeing, 50).
activity(shopping, 100).
activity(food_tasting, 75).
activity(beach, 25).
activity(hiking, 30).
activity(museum, 40).

% Define the budget predicate
% Note: Budget should be specified as an argument
budget(Budget) :- Budget >= 1000.

% Define the recommend predicate
recommend(Destination, Activity, Budget) :-
    destination(Destination, Cost),
    activity(Activity, ActivityCost),
    TotalCost is Cost + ActivityCost,
    budget(Budget),
    TotalCost =< Budget.

% Example usage:
% ?- recommend(Destination, Activity, Budget).
% This will recommend a Destination and Activity that fit the user's preferences and budget.
% ?- recommend(Destination, Activity, 1500).

%====================================================================
% Graph Search
% Define the graph using edge/2 facts
edge(a, b).
edge(a, c).
edge(b, d).
edge(c, d).
edge(c, e).
edge(d, e).

% Define the path predicate that initiates the DFS
path(Start, End, Path) :-
    dfs(Start, End, [Start], Path).

% Define the depth-first search (DFS) predicate
dfs(Node, End, Visited, Path) :-
    Node == End,                      % If the current node is the end node
    reverse(Visited, Path).           % Reverse the visited list to get the path
dfs(Node, End, Visited, Path) :-
    edge(Node, Next),                 % Find a connected node
    not(member(Next, Visited)),       % Ensure the node has not been visited
    dfs(Next, End, [Next|Visited], Path). % Continue the search with the new node

% ?- path(a, e, Path).
% ?- path(b, e, Path).

