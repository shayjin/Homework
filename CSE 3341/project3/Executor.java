import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Executor {
    public  static Map<String, Integer> global;       
    public static Stack<Map<String, Integer>> stack;  
    static List<Integer> heap; 

    static void init() {
        global =new HashMap<>();
        stack = new Stack<>();
        heap = new ArrayList<>();
    }

    public static void allocate(String name, int value) {
        if (stack.isEmpty()) {
            global.put(name, value);
        } else {
            Map<String, Integer> top = stack.pop();
            top.put(name, value);
            stack.push(top);
        }
    }

    public static void allocateOnHeap(String name) {
        boolean contains = false;

        for (int i = 0; i < stack.size() - 1 ; i++) {
            if (stack.get(i).containsKey(name)) {
                heap.add(stack.get(i).get(name));
                contains = true;
                break;
            }
        }

        if (!contains) heap.add(global.get(name));
    }

    public static int search(String name) {
        for (int i = 0; i < stack.size() - 1 ; i++) {
            if (stack.get(i).containsKey(name)) {
                return stack.get(i).get(name);
            }
        }

       return global.get(name);
    }
}
