#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>

// 使用这个宏来将变量的字面量打印出来
#define _STR(v) #v
#define STR(v)  _STR(v)

#if 0 // 用 dts/playground/props-basics.overlay

// 在设备树中定义了 aliases 和 chosen 节点之后
// 可以直接使用 `DT_ALIAS` 和 `DT_CHOSEN` 加上
// 定义的引用的属性名来访问一个节点
// 这里可以去看`dts/playground/props-basics.overlay`
// 但是三种方式最后展开得到的节点都是 `/node_with_props`
#    define NODE_PROPS_ALIAS_BY_LABEL   DT_ALIAS(alias_by_label)
#    define NODE_PROPS_ALIAS_BY_PATH    DT_ALIAS(alias_by_path)
#    define NODE_PROPS_ALIAS_BY_STRING  DT_ALIAS(alias_as_string)

#    define NODE_PROPS_CHOSEN_BY_LABEL  DT_CHOSEN(chosen_by_label)
#    define NODE_PROPS_CHOSEN_BY_PATH   DT_CHOSEN(chosen_by_path)
#    define NODE_PROPS_CHOSEN_BY_STRING DT_CHOSEN(chosen_as_string)

// 我们也可以使用 `DT_STRING_TOKEN` 来将字符串转换为一个
// 合法的 变量/函数 名
#    define STRING_TOKEN                DT_STRING_TOKEN(NODE_PROPS_ALIAS_BY_PATH, string)
// `/node_with_props`中 string 的值是 "foo bar baz"
// 等价于：
// #define STRING_TOKEN foo_bar_baz
// 会自动将非数字非字符转换为下划线
uint8_t STRING_TOKEN; // 其实定义了一个 uint8_t foo_bar_baz

// 用于 `DT_FOREACH_PROP_ELEM`
#    define PRINTK_FOREACH_STRING(node_id, prop, idx)                        \
        do                                                                   \
        {                                                                    \
            printk("[%d] -- %s\n", idx, DT_PROP_BY_IDX(node_id, prop, idx)); \
        } while (0);

typedef struct
{
    bool existent_boolean;
    int int_value;
    char *str;
    int enum_int_value;
    char *enum_str_value;
} values_t;

const values_t values = {
    .existent_boolean = DT_PROP(NODE_PROPS_ALIAS_BY_LABEL, existent_boolean),
    .int_value = DT_PROP(NODE_PROPS_ALIAS_BY_PATH, int),
    .str = DT_PROP(NODE_PROPS_ALIAS_BY_STRING, string),
    .enum_int_value = DT_PROP(NODE_PROPS_CHOSEN_BY_PATH, enum_int),
    .enum_str_value = DT_PROP(NODE_PROPS_CHOSEN_BY_PATH, enum_string),
};

int main(void)
{
    printk("values = {\n");
    printk("  .existent_boolean     = %d\n", values.existent_boolean); // = 1
    printk("  .int_value            = %d\n", values.int_value); // = 1
    printk("  .str                  = %s\n", values.str); // = "foo bar baz"
    printk("  .enum_int_value       = %d\n", values.enum_int_value); // = 200
    printk("  .enum_str_value       = %s\n", values.enum_str_value); // = "whatever"
    printk("}\n");

    // 对于枚举类型可以使用 `DT_ENUM_IDX` 来访问指定成员在
    // 枚举中的索引
    printk("The index within `enum_int` of selected value '%d' is %d\n",
           values.enum_int_value,
           DT_ENUM_IDX(NODE_PROPS_CHOSEN_BY_LABEL, enum_int));

    printk("The index within `enum_str` of selected value '%s' is %d\n",
           values.enum_str_value,
           DT_ENUM_IDX(NODE_PROPS_CHOSEN_BY_LABEL, enum_string));

    // 查看 `DT_STRING_TOKEN` 的效果
    printk("property string after `DT_STRING_TOKEN`:%s\n", STR(STRING_TOKEN));

    // 对于设备树中的数组类型
    const size_t int_array_len = DT_PROP_LEN(NODE_PROPS_ALIAS_BY_PATH, array);
    const uint32_t int_array[] = DT_PROP(NODE_PROPS_CHOSEN_BY_LABEL, array);
    // 等价于：
    // const uint32_t int_array[] = {10 /* 0xa */, 11 /* 0xb */, 12 /* 0xc */};

    const size_t uint8_array_len = DT_PROP_LEN(NODE_PROPS_ALIAS_BY_PATH, uint8_array);
    const uint8_t uint8_array[] = DT_PROP(NODE_PROPS_ALIAS_BY_STRING, uint8_array);
    // 等价于：
    // const uint8_t uint8_array[] = {0x12, 0x34, 0xAB};

    if (int_array_len != sizeof(int_array) / sizeof(int_array[0]) ||
        uint8_array_len != sizeof(uint8_array) / sizeof(uint8_array[0]))
    {
        printk("error!\n");
    }
    else
    {
        printk("ok!\n");
    }

    // 数组类型，Zephyr 提供了 `DT_FOREACH_PROP_ELEM` 宏来遍历整个数组
    // 但是前提是需要自己定义遍历函数或者宏
    DT_FOREACH_PROP_ELEM(NODE_PROPS_ALIAS_BY_PATH, string_array, PRINTK_FOREACH_STRING);

    while (1)
    {
        k_msleep(1000);
    }

    return 0;
}

#else // 用 dts/playground/props-phandles.overlay

// `DT_PATH` 是一个接受可变参数的宏，可以忽略
// 根节点，将每个子节点都作为一个参数来调用路径
// 比如：
// /node_parent/node_child1/node_child2
// 可以使用下面的宏来访问：
// DT_PATH(node_parent, node_child1, node_child2)
#    define NODE_REFS DT_PATH(node_refs)

// 可以使用 `DT_PHANDLE` 来获取一个节点的
// `phandle` 参数
#    define NODE_A_PHANDLE_BY_LABEL DT_PHANDLE(NODE_REFS, phandle_by_label)
#    define NODE_A_PHANDLE_BY_PATH  DT_PHANDLE(NODE_REFS, phandle_by_path)

// 使用 `DT_PHANDLE_BY_IDX` 来访问一个节点的
// `phandles` 数组中的指定索引的 `phandle`
#    define NODE_A_PHANDLES DT_PHANDLE_BY_IDX(NODE_REFS, phandle_array_of_refs, 0)
#    define NODE_B_PHANDLES DT_PHANDLE_BY_IDX(NODE_REFS, phandle_array_of_refs, 1)

// 如何使用 `phandle` 来间接访问一个节点的某个属性
uint32_t val_from_dummy = DT_PROP(NODE_A_PHANDLE_BY_LABEL, dummy_value);
// 上述这种直接通过节点访问属性的方法很常见
// 但使我们可以使用 `phandle` 来间接访问它
// 就像下面这样:
// 通过访问一个包含目标节点的 `phandle`
// 的节点，来访问目标节点的指定属性
uint32_t val_from_phandle_by_label = DT_PROP_BY_PHANDLE(NODE_REFS, phandle_by_label, dummy_value);
uint32_t val_from_phandle_by_path = DT_PROP_BY_PHANDLE(NODE_REFS, phandle_by_path, dummy_value);
uint32_t val_from_phandles = DT_PROP_BY_PHANDLE_IDX(NODE_REFS, phandle_array_of_refs, 0, dummy_value);

// 访问 `phandle-array` 的参数(伪代码)
// 定义一个结构体用来表示
// node_a 和 node_b 的参数
/*
@code 
typedef struct
{
    uint32_t cell_one;
    uint32_t cell_two;
} node_sepc_t;

// 具体的绑定文件在 `dts/bindings/custom,cells-a.yaml` 和 `dts/bindings/custom,cells-b.yaml`
// API中带有 `_OR` 的作用都是在属性不存在的时候提供一个默认值
#    define NODE_DT_SPEC_GET_BY_IDX(node_id, prop, idx)                            \
        {                                                                          \
            .cell_one = DT_PHA_BY_IDX(node_id, prop, idx, name_of_cell_one),       \
            .cell_two = DT_PHA_BY_IDX_OR(ndoe_id, porp, idx, name_of_cell_two, 0), \
        }
// 获取节点

// node_a = {.cell_one = 1, .cell_two = 2};
node_sepc_t node_spec_a = NODE_DT_SPEC_GET_BY_IDX(NODE_REFS, phandle_array_of_refs, 0);
// node_b = {.cell_one = 1, .cell_two = 0};
node_sepc_t node_spec_b = NODE_DT_SPEC_GET_BY_IDX(NODE_REFS, phandle_array_of_refs, 1);

// 配置节点
configure_node(node_a);
configure_node(node_b);
*/

int main(void)
{
    printk("%s = %x\n", STR(val_from_dummy), val_from_dummy);
    printk("%s = %x\n", STR(val_from_phandle_by_label), val_from_phandle_by_label);
    printk("%s = %x\n", STR(val_from_phandle_by_path), val_from_phandle_by_path);
    printk("%s = %x\n", STR(val_from_phandles), val_from_phandles);

    while (1)
    {
        k_msleep(500);
    }

    return 0;
}

#endif
