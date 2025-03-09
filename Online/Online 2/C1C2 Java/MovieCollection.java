public class MovieCollection {
    private int movieCount;
    private Movie[] movies;

    public MovieCollection(int howManyMovies) {
        movies = new Movie[howManyMovies];
        movieCount = 0;
    }

    public void addMovie(Movie m) {
        movies[movieCount] = m;
        movieCount += 1;
    }

    public void searchMovie(String title) {
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].getTitle().equalsIgnoreCase(title)) {
                movies[i].displayDetails();
                return;
            }
        }
        System.out.println("Not in Collection.");
    }

    public void rentMovie(String title) {
        for (int i = 0; i < movieCount; i++) {
            if (movies[i].getTitle().equalsIgnoreCase(title)) {
                if (movies[i].rent())
                    System.out.printf("Rent Successful! Available copies for %s: %d.\n", movies[i].getTitle(),
                            (movies[i].getTotalCopies() - movies[i].getRentedCopies()));
                else
                    System.out.printf("Error: All copies of \"%s\" are currently rented out.\n", movies[i].getTitle());
                return;
            }
        }
    }
}
