import io.restassured.RestAssured;
import io.restassured.response.Response;
import org.json.JSONObject;
import org.testng.annotations.Test;

import static io.restassured.RestAssured.given;
import static io.restassured.RestAssured.when;
import static org.hamcrest.Matchers.equalTo;
import static org.hamcrest.Matchers.hasItems;

public class RestTesting {

    @Test
    public void test_NumberOfCircuitsFor2017Season_ShouldBe20() {

        given().
                when().
                get("http://localhost:8080/swagger-ui.html#/api/v1/private/configurations/payment").

                then().
                assertThat().
                statusCode(200).log();
    }
    @Test
    public static void getResponseStatus(){
        int statusCode= given().queryParam("CUSTOMER_ID","68195")
                .queryParam("PASSWORD","1234!")
                .queryParam("Account_No","1") .when().get("http://demo.guru99.com/V4/sinkministatement.php").getStatusCode();
        System.out.println("The response status is "+statusCode);

        given().when().get("http://localhost:8080/swagger-ui.html#/api/v1/private/configurations/payment").then().assertThat().statusCode(200);
    }

    @Test
    public static void validatetheresponse()
    {
        RestAssured request = null;
        Response response = request.post("http://localhost:8080/swagger-ui.html#/api/v1/private/configurations/payment");
        System.out.println("The status received: " + response.statusLine());

    }

    @Test
    public static void getIDofData()
    {
            given().get("https://reqres.in/api/users?page=2")
                    .then()
                    .statusCode(200)
                    .body("data.id[0]",equalTo(7));
    }

    @Test
    public static void firstnameCheck()
    {
        given().get("https://reqres.in/api/users?page=2")
                .then()
                .statusCode(200)
                .body("data.id[1]",equalTo(8))
                .body("data.first_name",hasItems("Michael","Lindsay"));
    }

    @Test
    public static void PostTest()
    {
        JSONObject request = new JSONObject ( ) ;
        request.put ("name","Raghav");
        request.put ("job","Teacher");

        given().
        body (request.toString()).
                when().
                post("https://reqres.in/api/users").
                then().statusCode(202);
    }

    @Test
    public static void DeleteOperation()
    {
        when().
                delete("https://reqres.in/api/users/2")
                .then()
                .statusCode(204).log().all();
    }




}
