Feature: Create a Store
    Scenario Outline: I was on Create Store Tab And have <Store Name> , <Unique Store Code> , <Store-Phone> ,<Store-Email Address>,<Address>, <City> , <Postal-Code>, <Country>, <State>,<Supported-Language>,<Weight Unit>,<Size Unit>,<Default Language>,<Web-Site Operating Since>, <Retailer>
        Given : I Launched the Chrome Web Browser And Login the Portal
         When I enter  <Store Name> in the Store name field
And enter <Unique Store Code> in the Unique Store code field
And enter <Store-PhoneNo> in the Store-PhoneNo field
And enter <Store-Email Address> in the Store Email Address Field
And enter <Address> in the Address Field
And enter <City> in the city field
And enter <Postal-Code> in the postal code field
And enter <Country> in the country field
And enter <State> in the state field
And enter <Supported-Language> in the Supported Language Field
And Enter <Weight Unit> in the Weight Field
And Enter <Size Unit> in the size unit field
And enter <Default Language> in the list menu
And  enter <Web-Site Operating Since> in the Web-Site Operating Since list menu
And enter <Retailer> in the list menu
Then Store would successfully create And added in-store list

      Examples:
        | Store Name | Unique Store Code | Store-PhoneNo | Store-Email Address | Address         | City      | Postal-Code | Country | State | Supported-Language | Weight Unit | Size Unit | Default Language | Web-Site Operating Since | Retailer  |
        |  Bismillah |      123          | +923166344640 | muhammad@m.com      |Depalpur,street 2|  Depalpur |    56128    |    Pak  |Punjab |     English        |      KG     |     IN   |        English    |       2020               |   default |
        |  empty     |     empty         |    empty      |   empty             | empty           |  empty    |  empty      |    empty|empty  |       empty        |     empty   |   empty  |        empty      |      empty               | empty     |
        |  -1        |     -1            |    -1         |      -1             | -1              |  -1       |  -1         |       -1|  -1   |          -1        |        -1   |      -1  |           -1      |      -1                  | -1        |
        |  123456789 |      123          | +923166344640 | 123456789           |123456789        |  123456789|    56128    |    Pak  |Punjab |     English        |      KG     |     IN   |        English    |       2020               |   default |
