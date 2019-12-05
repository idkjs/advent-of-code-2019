module Data = {
  let data = [
    147129,
    128896,
    86366,
    121702,
    106854,
    107418,
    96021,
    116460,
    100395,
    149526,
    146314,
    56215,
    59911,
    96016,
    86483,
    115837,
    84522,
    137658,
    105769,
    149691,
    127499,
    95302,
    53109,
    101940,
    106343,
    140421,
    88790,
    105898,
    68085,
    85027,
    99405,
    116253,
    55338,
    50009,
    58244,
    145865,
    145270,
    148777,
    139954,
    147397,
    128691,
    63082,
    144279,
    76143,
    73006,
    105508,
    62796,
    144807,
    66587,
    50828,
    143778,
    73793,
    76852,
    119991,
    103181,
    105618,
    106320,
    136345,
    68771,
    82534,
    94528,
    65802,
    74863,
    139414,
    65854,
    149543,
    87063,
    85691,
    148931,
    139653,
    90728,
    100710,
    110159,
    131407,
    129323,
    145874,
    127227,
    129006,
    105828,
    67468,
    136905,
    89273,
    133439,
    78783,
    90794,
    116324,
    132792,
    135413,
    142086,
    62659,
    59178,
    59080,
    122465,
    62753,
    112104,
    92551,
    90638,
    145232,
    133984,
    139994,
  ];
};

/* First step is convert our int value to a float so that we divide it we get any decimal values as well. We do that by passing each item to `float` in the first step of our map. Per the instruction, we have to round down any decimal left over from the calculaton. Or in other words, we have to disregard any decimal point values. We can achiev this by converting the float back to an int. As I write, I realize that I might get the same answer by not converting at all. Just using ints will disregard decimal values all together. Question is, does ocaml round up or down. Trying it out, I get the same answer so it must be rounding down. Both solutions are below. We then subtract two from the result. Lastly we use [Belt.List.reduce](https://bucklescript.github.io/bucklescript/api/Belt.List.html#VALreduce) passing in `0` as our accumulator, and `(+)` as the add operation we want done on each item.   */

/* divide returned float by 3 */
let divideFloatBy3 = mass => mass /. 3.;
/* divide returned int by 3 */
let divideIntBy3 = mass => mass / 3;
/* convert a float back to int thereby cutting of any decimal remainder */
let roundDown = mass => mass->int_of_float;
/* subtract two from the result*/
let subtractTwo = int => int - 2;

open Belt.List;
let main = () => {
  let result =
    Data.data
    |> map(_, float)
    |> map(_, divideFloatBy3)
    |> map(_, roundDown)
    |> map(_, subtractTwo)
    |> reduce(_, 0, (+));
  result |> Js.log; /*3511949*/
};
main();
let main = () => {
  let convert = value =>
    value |> float |> divideFloatBy3 |> roundDown |> subtractTwo;
  let result = Data.data |> map(_, convert) |> reduce(_, 0, (+));
  result |> Js.log; /*3511949*/
};
main();

let main = () => {
  let result =
    Data.data
    |> map(_, divideIntBy3)
    |> map(_, subtractTwo)
    |> reduce(_, 0, (+));
  result |> Js.log; /*3511949*/
};
main();