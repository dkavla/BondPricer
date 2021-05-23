# Bond Pricing Program

## What It Does
This is a C++ program that will accept specific user input data, and take that same data to price the bond. The pricing of the bond will take the bond's cash flows and discount them to the present with the calculated Yield to Maturity. Afterwards it compares the current market value of the bond and the calculated price and will display it to the user if its selling at a premium, discount, or at par. Lastly, the program will calculate the bonds duration, the bond's current yield, as well as its convexity.

## Additonal Information
Duration measures the bond's sensitivity due to changes in interest rates.
* Takes into account the main risk factors that affect the bond, such as credit risk and interest rate risk
* There are two types of duration calculations: the Macaulay duration and the Modified duration (the program will have both as their own individual member function)

Each bond in this program is represented as an object of the class Bond that will be defined in a seperate header file within the project files (will be specified)

## Things That Are Be Bound To Change
* The first version of the program will store the bond info and calculations in a file, but plans to make the program store the info inside a database.

## Formulas Being Used
Yield to Maturity
* ![Image 5-4-21 at 4 30 PM](https://user-images.githubusercontent.com/52176346/117065908-0cb43100-acf6-11eb-9e06-cf6d8d0f0575.jpg)

Macaulay Duration
* ![Image 5-4-21 at 4 51 PM](https://user-images.githubusercontent.com/52176346/117068190-f360b400-acf8-11eb-91cf-573c1f33aed4.jpg)

Modified Duration
* ![Image 5-4-21 at 4 52 PM](https://user-images.githubusercontent.com/52176346/117068284-15f2cd00-acf9-11eb-8e9b-419c79b013fd.jpg)

Convexity
* ![Image 5-4-21 at 4 56 PM](https://user-images.githubusercontent.com/52176346/117068819-bf39c300-acf9-11eb-95da-ad8af8104c19.jpg)

Current Yield
* ![Image 5-4-21 at 5 04 PM](https://user-images.githubusercontent.com/52176346/117069833-f8befe00-acfa-11eb-8cc3-2055bf640698.jpg)


