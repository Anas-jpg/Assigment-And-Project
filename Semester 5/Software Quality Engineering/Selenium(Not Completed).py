from selenium import webdriver

driver = webdriver.Chrome("C:\\chromedriver\\chromedriver.exe")

keyword = "PakVSZim"

driver.get("http://www.google.com/search?q="+keyword)


