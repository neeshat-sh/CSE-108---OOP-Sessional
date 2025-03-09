public class Product {
    private String name;
    private String category;
    private double price;
    private int totalQuantity;
    private int soldQuantity;

    public Product() {
        name = null;
        category = null;
        price = -1;
        totalQuantity = -1;
        soldQuantity = -1;
    }

    public Product(String name, String category, double price, int totalQuantity, int soldQuantity) {
        this.name = name;
        this.category = category;
        this.price = price;
        this.totalQuantity = totalQuantity;
        this.soldQuantity = soldQuantity;
    }

    public Boolean verifyPrice(double price) {
        return price > 0;
    }

    public Boolean verifyQuantity(int soldQuantity) {
        return soldQuantity <= this.totalQuantity;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setTotalQuantity(int totalQuantity) {
        this.totalQuantity = totalQuantity;
    }

    public void setSoldQuantity(int soldQuantity) {
        this.soldQuantity = soldQuantity;
    }

    public String getName() {
        return this.name;
    }

    public int availableQuantity() {
        return totalQuantity - soldQuantity;
    }

    public void display() {
        System.out.println("Product details:");
        System.out.println("- Name: " + this.name);
        System.out.println("- Category: " + this.category);
        System.out.println("- Price: " + this.price);
        System.out.println("- Available quantity: " + availableQuantity());
    }

    public void sell(int quantity) {
        soldQuantity += quantity;
    }
}
