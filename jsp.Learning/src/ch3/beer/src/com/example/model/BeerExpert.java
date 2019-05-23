/*
 * 在 beer\ 路径下运行如下编译命令
 * javac -d classes src/com/example/model/BeerExpert.java
 * 会在 beer\classes\com\example\model\ 路径下生成文件：BeerExpert.class
 */
package com.example.model;
import java.util.*;

public class BeerExpert {
	public List getBrands(String color) {
		List brands = new ArrayList();
		if (color.equals("amber")) {
			brands.add("Jack Amber");
			brands.add("Red Moose");
		}
		else {
			brands.add("Jail Pale Ale");
			brands.add("Gout Stout");
		}

		return(brands);
	}
}
