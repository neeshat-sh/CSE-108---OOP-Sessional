public class Movie {
    private String title;
    private String genre;
    private double rating;
    private int totalCopies;
    private int rentedCopies;

    public Movie() {
        title = null;
        genre = null;
        rating = -1;
        totalCopies = -1;
        rentedCopies = -1;
    }

    public Movie(String title, String genre, int rating, int totalCopies, int rentedCopies) {
        this.title = title;
        this.genre = genre;
        this.rating = rating;
        this.totalCopies = totalCopies;
        this.rentedCopies = rentedCopies;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setGenre(String genre) {
        this.genre = genre;
    }

    public void setRating(double rating) {
        if(verifyRating(rating))
            this.rating = rating;
    }

    public void setTotalCopies(int totalCopies) {
        this.totalCopies = totalCopies;
    }

    public void setRentedCopies(int rentedCopies) {
        this.rentedCopies = rentedCopies;
    }

    public String getTitle() {
        return this.title;
    }

    public String getGenre() {
        return this.genre;
    }

    public double getRating() {
        return this.rating;
    }

    public int getTotalCopies() {
        return this.totalCopies;
    }

    public int getRentedCopies() {
        return this.rentedCopies;
    }

    public void displayDetails() {
        System.out.println("Movie details: ");
        System.out.println("-Title: " + this.title);
        System.out.println("-Genre: " + this.genre);
        System.out.println("-Rating: " + this.rating);
        int availableCopies = this.totalCopies - this.rentedCopies;
        if (availableCopies > 0)
            System.out.println("-Available Copies: " + availableCopies);
        else
            System.out.println("-Not Available for rent.");
    }

    public Boolean rent() {
        if(rentedCopies < totalCopies)
        {
            rentedCopies += 1;
            return true;
        }
        return false;
    }

    public Boolean verifyRating(double rating) {
        return rating >= 0 && rating <= 10;
    }
}