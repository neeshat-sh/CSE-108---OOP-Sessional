public class Inventory {
    private int productCount;
    private Product[] products;

    public Inventory(int howManyProducts) {
        products = new Product[howManyProducts];
        productCount = 0;
    }

    public void addProduct(Product p) {
        products[productCount] = p;
        productCount += 1;
    }

    public void searchProduct(String name) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].getName().equals(name)) {
                products[i].display();
                return;
            }
        }
        System.out.println("No such product in inventory.");
    }

    public void sellProduct(String name, int quantity) {
        for (int i = 0; i < productCount; i++) {
            if (products[i].getName().equals(name)) {
                if (products[i].verifyQuantity(quantity)) {
                    products[i].sell(quantity);
                    System.out.printf("Sale successful! Available quantity for %s: %d", name,
                            products[i].availableQuantity());
                }
                else
                    System.out.println("Not enough products");
                return;
            }
        }
        System.out.println("Product not found.");
    }
}
