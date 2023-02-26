import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Executor {
    public static Map<String, Integer> global;       
    public static Stack<Map<String, Integer>> stack;  
    static List<Integer> heap; 
    static Map<String, String> shared;
    public static Scanner scanner;


    static void init() {
        global =new HashMap<>();
        stack = new Stack<>();
        heap = new ArrayList<>();
        shared = new HashMap<>();
    }

    public static void addContext() {
        stack.push(new HashMap<>());
    }

    public static void deleteContext() {
        stack.pop();
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

    public static void allocateShare(String ref, String name) {
        shared.put(ref, name);
    }

    public static void allocateOnHeap(String name) {
        boolean contains = false;

        for (int i = 0; i < stack.size() - 1 ; i++) {
            if (stack.get(i).containsKey(name)) {
                heap.add(stack.get(i).get(name));
                contains = true;
                return;
            }
        }

        if (!contains) heap.add(global.get(name));
    }

    public static void assign(String name, int value) {
        if (shared.containsKey(name)) {
            assign(shared.get(name), value);
        } else {
            for (int i = stack.size() - 1; i >= 0 ; i--) {
                if (stack.get(i).containsKey(name)) {
                    stack.get(i).put(name, value);
                    return;
                }
            }
    
            if (global.containsKey(name)) {
                global.replace(name, value);
            }
        }
    }

    public static int search(String name) {
        if (shared.containsKey(name)) {
            return search(shared.get(name));
        }

        for (int i = stack.size() - 1; i >= 0 ; i--) {
            if (stack.get(i).containsKey(name)) {
                return stack.get(i).get(name);
            }
        }

        if (global.containsKey(name)) return global.get(name);


        return 0;
    }
}
