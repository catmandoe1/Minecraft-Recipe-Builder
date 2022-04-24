# Minecraft-Recipe-Builder
Json recipe builder for Forge Minecraft 1.12.2 - 1.16.1+ **(Unsure about versions above 1.12.2 working with oredict)**

This Program makes it easy to create recipes files for modding in minecraft java instead of writting them out yourself.

The Recipe builder will create a .json file that you add into your recipe package located in "src.main.resources.assets.modid.recipes"

# How to work it
A little walk through of how to use the recipe builder

## Basic
**1. Add item ids into the item id list by typing in the input box and clicking _Add_.**

![image](https://user-images.githubusercontent.com/73958516/162012881-d67255aa-30d9-4200-9eda-f2d34ef04100.png)

**Clear list** will remove all selections and all enteries on the list

**2. Select a shape type (default is _shaped_)**

![image](https://user-images.githubusercontent.com/73958516/162014285-2b035dca-8d9f-445a-b628-5e5ce064b287.png)

**3. Create the recipe**

![image](https://user-images.githubusercontent.com/73958516/162015073-31e16df5-eb30-4f77-aca5-0ab87c046dd5.png)

The Amount counter can go up to 64 and low as 1 *(Unstackable items such as tools will only give 1)*

**4. Create the file**

![image](https://user-images.githubusercontent.com/73958516/162015819-55279b39-010e-4067-baef-ad45e6654861.png)

Click the **Create Json File** after giving the file a name. 

The File will be created in the directory that the recipe builder is in.

![image](https://user-images.githubusercontent.com/73958516/162017147-a1fe23ae-dbec-4b38-838a-34df122b104d.png)

Keep in mind that if there is a file with the same name (with the prefix **.json**) it will override it.

**5. Insert into recipe package**

Put the json file that was created into your **recipes** package in your mod. *(im using eclipse)*

![image](https://user-images.githubusercontent.com/73958516/162021435-0242e7a8-7053-4753-87b8-e3ce8ab34826.png)

**6. Test**

Now test your recipes in your favourite IDE

![image](https://user-images.githubusercontent.com/73958516/162022625-e47d8376-29cc-4f33-8d1d-620c89d1500a.png)

*If your recipe doesn't work, it's most likely your item id wasn't correct.*





## Advanced
**OreDictionary** is used to unify items between mods. 
This allows recipes to use either item to produce the same result. More at [Forge Docs](https://mcforge.readthedocs.io/en/1.12.x/utilities/oredictionary/)

**Variants** of blocks (such as planks in **1.12.2**) use the same item id, but using the data tag can differentiate check variant.

An example of this is oak planks have the id minecraft:planks, but their data is **0**. Spruce planks have the same id but their data is **1**.

**1. Change the tab to advanced and create your recipe**

![image](https://user-images.githubusercontent.com/73958516/162020715-8b98efa6-af21-41a6-8417-fb10f38e40e6.png)

**2. Create the file**

![image](https://user-images.githubusercontent.com/73958516/162020932-e5f308ef-5f98-43c5-9706-76e29c24d025.png)

Make sure to change it over to advanced when creating the file.





## Format
The recipe builder does all of the formatting work automatically so its just some information on how recipes are made.

### Shaped
Shaped is the standard recipe style meaning that the items in the crafting table have to be in a specific order and shape to craft a item in varing amounts.

The format that this type of recipe style is:
```
{
	"type": "minecraft:crafting_shaped",
	"pattern": [
		"AAA",
		" B ",
		" B "
	],
	"key": {
		"A": {
			"item": "minecraft:iron_ingot"
		},
		"B": {
			"item": "minecraft:stick"
		}
	},
	"result": {
		"item": "minecraft:iron_pickaxe"
	}
}
```

### Shapeless
Shapeless is the other type of recipe style that is not used as much but is handy with small recipes. 
They are essentialy just a list of what is needed to be in the crafting table to make the result. 
The items needed can be in any solt and in any shape to craft the item.
*(Adding 2 of the same ingredients will increase the count needed of that item)*

The format that this type of recipe style is:
```
{
	"type": "forge:ore_shapeless",
	"result": {
		"item": "goodmod:steel_dust",
		"count": 2
	},
	"ingredients": [
		{
			"item": "goodmod:coal_dust"
		},
		{
			"item": "goodmod:iron_dust"
		}
	]
}
```
