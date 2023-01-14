import time
from behave import *
from selenium import webdriver
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.common.by import By
from pytest_bdd import scenario, given, when, then


driver: WebDriver = webdriver.Chrome("C:\\chromedriver\\chromedriver.exe")

@given(u': I Launched the Chrome Web Browser And Login the Portal')
def loginportal():
    driver.get("http://localhost:4200")
    time.sleep(0.75)
    driver.find_element(By.NAME, "username").send_keys("admin@shopizer.com")
    time.sleep(0.75)
    driver.find_element(By.NAME, "password").send_keys("password")
    time.sleep(0.75)
    ele = driver.find_element(By.CLASS_NAME, "container-login100-form-btn")
    time.sleep(2)
    ele.click()
    time.sleep(2)
    driver.get("http://localhost:4200/#/pages/store-management/create-store")
loginportal()








time.sleep(2)

# All fields Empty and Try to Create Store
@When(u'I All  empty Fields in the Store ')
def ALLEMPTY():
    time.sleep(1)
    driver.find_element(By.CSS_SELECTOR, "#name").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#code").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#email").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#address").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#city").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#postalCode").send_keys("")
    time.sleep(0.75)
    driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/form[1]/nb-card[1]/nb-card-body[1]/div[6]/div[1]/nb-checkbox[2]/label[1]/span[1]").click()
    time.sleep(2)





ALLEMPTY()
time.sleep(2)

element = driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/nb-card-header[1]/div[2]/button[1]")

if driver.execute_script("arguments[0].click();", element) == None:
    print("Button Not Executed")
else:
    driver.execute_script("arguments[0].click();", element)

# All Fields Data Entered
time.sleep(2)
driver.get("http://localhost:4200/#/pages/store-management/create-store")



# All fields Negative and Try to Create Store
@When(u' All  empty Fields in the Store are Negative ')
def ALLNegative():
    time.sleep(1.75)
    driver.find_element(By.CSS_SELECTOR, "#name").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#code").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#email").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#address").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#city").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#postalCode").send_keys("-1")
    time.sleep(0.75)
    driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/form[1]/nb-card[1]/nb-card-body[1]/div[6]/div[1]/nb-checkbox[2]/label[1]/span[1]").click()
    time.sleep(2)





ALLNegative()
time.sleep(2)

element = driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/nb-card-header[1]/div[2]/button[1]")

if driver.execute_script("arguments[0].click();", element) == None:
    print("Button Not Executed")
else:
    driver.execute_script("arguments[0].click();", element)


time.sleep(2)
driver.get("http://localhost:4200/#/pages/store-management/create-store")



# All fields Numbers(positive) and Try to Create Store
@When(u' All   Fields in the Store are Positive ')
def ALLPositive():
    time.sleep(1.75)
    driver.find_element(By.CSS_SELECTOR, "#name").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#code").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#email").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#address").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#city").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.CSS_SELECTOR, "#postalCode").send_keys("12345678")
    time.sleep(0.75)
    driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/form[1]/nb-card[1]/nb-card-body[1]/div[6]/div[1]/nb-checkbox[2]/label[1]/span[1]").click()
    time.sleep(2)





ALLPositive()
time.sleep(2)

element = driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/nb-card-header[1]/div[2]/button[1]")

if driver.execute_script("arguments[0].click();", element) == None:
    print("Button Not Executed")
else:
    driver.execute_script("arguments[0].click();", element)


time.sleep(2)
driver.get("http://localhost:4200/#/pages/store-management/create-store")
time.sleep(2)


time.sleep(1.75)

# @when(u':Store would successfully create And added in-store list')
driver.find_element(By.CSS_SELECTOR, "#name").send_keys("Bismillah")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#code").send_keys("123")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#phone").send_keys("923166344640")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#email").send_keys("muhaasdsammad@anas.com")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#address").send_keys("Depalpur,street ")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#city").send_keys("Depalpur")
time.sleep(0.75)
driver.find_element(By.CSS_SELECTOR, "#postalCode").send_keys("56128")
time.sleep(0.75)
driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/form[1]/nb-card[1]/nb-card-body[1]/div[6]/div[1]/nb-checkbox[2]/label[1]/span[1]").click()

time.sleep(3)


element = driver.find_element(By.XPATH, "/html[1]/body[1]/ngx-app[1]/div[1]/ngx-pages[1]/ngx-sample-layout[1]/nb-layout[1]/div[1]/div[1]/div[1]/div[1]/div[1]/nb-layout-column[1]/ngx-store-management[1]/div[1]/div[1]/ngx-store-creation[1]/div[1]/ngx-store-form[1]/div[1]/nb-card-header[1]/div[2]/button[1]")

time.sleep(3)
driver.execute_script("arguments[0].click();", element)

time.sleep(2)
driver.close()
