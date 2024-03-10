package model.adts;

public class Tuple<E1, E2, E3> {
    private final E1 first;
    private final E2 second;
    private final E3 third;

    public Tuple(E1 first, E2 second, E3 third)
    {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    public E1 getFirst()
    {
        return this.first;
    }

    public E2 getSecond()
    {
        return this.second;
    }

    public E3 getThird()
    {
        return this.third;
    }
}
