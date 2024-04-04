const std = @import("std");
const stdout = std.io.getStdOut().writer();
const words = @embedFile("./resources/0042_words.txt");
const sqrt = std.math.sqrt;

fn getWordValue(word: []const u8) u64 {
    var value: u64 = 0;
    for (word) |c| {
        value += c - 'A' + 1;
    }

    return value;
}

fn isTriangular(n: u64) bool {
    const x = 8*n + 1;
    return x % sqrt(x) == 0;
}

pub fn main() !void {
    var word_it = std.mem.splitAny(u8, words, ",");
    var triangle_words: u64 = 0;

    while (word_it.next()) |word| {
        if (isTriangular(getWordValue(word[1..word.len - 1]))) {
            triangle_words += 1;
        }
    }

    try stdout.print("{}\n", .{triangle_words});
}
