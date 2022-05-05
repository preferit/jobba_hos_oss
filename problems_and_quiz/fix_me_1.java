/**
 * What do we have here?
 * Something is wrong what might that be?
 * Please fix this piece of code
 */

import ...

class Mathematician extends Thread {
    static Semaphore[] fork;
    int i;

    Mathematician (int i) {
        this.i=i;
    }

    public void run () {
        while(true) {
            think();
            fork[i].take();
            fork[(i+1)%4].take();
            eat();
            fork[i].give();
            fork[(i+1)%4].give();
        }
    }

    private void think (){
        ...
    }

    private void eat () {
        ...
    }

    public static void main (String[] args) {
        fork = new MutexSem[4];
        for (int i = 0; i < 4; i++) fork[i] = new MutexSem();
        for (int i = 0; i < 4; i++) (new Mathematician(i)).start();
    }
}
/**
 * If you have the answer, and if you have the intrest of working with us
 * please email your answer to alexander@preferit.se and let us set up a 
 * lunch meeting, where we can discuss a future employment at Preferit AB
 */
