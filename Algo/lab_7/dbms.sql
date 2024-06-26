-- Adib Sakhawat
-- IUT, 2024


use Social_Media

-- Task 2
db.runCommand({
    collMod: "users",
    validator: {
        $jsonSchema:{
            required : ["name", "password", "email"],
            properties:{
                name:{
                    bsonType: "string",
                    description: "must be a string and is required"
                },
                password:{
                    bsonType: "string",
                    description: "must be a string and is required"
                },
                email:{
                    bsonType: "string",
                    description: "must be a string and is required"
                }
            }
        }
    }
});

-- Task 3

db.runCommand({
    collMod: "posts",
    validator: {
        $jsonSchema:{
            required : ["content"],
            properties:{
                content:{
                    bsonType: "string",
                    description: "must be a string and is required"
                }
            }
        }
    }
});

-- Task 4: Insertion
--(a) 

db.users.insertOne({
    name: "John Doe",
    email: "doejohn@gmail.com",
    password: "doedoe"
});

--(b) 

db.users.insertOne({
    name: "Bucky Barns",
    email: "wintersoilder@gmail.com",
    password : "wintersol",
    dob : "19-07-1993",
    address : "Brooklyn",
    hobbies: ["reading", "gaming", "watching movies"]
})

-- (c) 

db.users.insertMany([
    {
        name: "Steve Rogers",
        email: "ca@avengers.com",
        password : "cap",
        dob : "04-07-1918",
        address : "Brooklyn",
        telephone: {
            work: 98512365,
            personal: 95124875
        }

    }
    ,
    {
        name: "Tony Stark",
        email: "ironman@avengers.com",
        password: "jarvis",
        dob: "29-05-1970",
        address: "Manhattan",
        telephone: {
            work: 92169856,
            personal: 93216584
        }
    }
]);

-- (d) 

db.posts.insertMany([
    {
        content: "I am Ironman",
        creation_time: new Date()
    },
    {
        content: "I can do this all day",
        creation_time: new Date()
    },
    {
        content: "I am inevitable",
        creation_time: new Date()
    },
    {
        content: "I am Groot",
        creation_time: new Date()
    }
]);

-- Task 5: Updating
-- (a) 

db.users.updateMany(
    { name: { $in: ["Steve Rogers", "Tony Stark"] } },
    { $set: { followers: ["Takia Farhin", "Tahsin Islam", "Adib Sakhawat", "Antara Arifa", "Farhan Abid", "Niaz Rahman"] } }
);


-- (b) 

db.users.updateMany(
    { name: { $in: ["John Doe", "Tony Stark"] } },
    { $set: { friends: ["Bucky Barns", "Steve Rogers"] } }
);

-- (c) 

db.posts.updateMany(
    { content: { $in: ["I am Ironman", "I am Groot"] } },
    { $set: { likes: ["John Doe", "Tony Stark", "Steve Rogers"] } }
);

-- (d) 

db.posts.updateMany(
    { $or: [
        { content: "I can do this all day" },
        { content: "I am inevitable" }
       
    ] },
    {
        $set: {
            comments: [
                { comment: "Where is spider-man?", commenter: "John Doe" },
                { comment: "Peace out", commenter: "Tony Stark" },
                { comment: "Life is too good", commenter: "Bucky Barns" }
            ]
        }
    }
);

-- 6. Data Retrieving
-- (a) 

db.posts.find().count();

-- (b) 

db.posts.find().sort({ creation_time: -1 });

-- (c) 

db.posts.find({ creation_time: { $gte: new Date(new Date().setDate(new Date().getDate() - 1)) } });

-- (d) 

db.users.find({ $where: "followers.length > 3" });

-- (e) 

db.users.find({ dob: { $gte: "01-01-1990", $lte: "31-12-2000" } });

-- (f) 

db.users.find().sort({ _id: 1 }).limit(3);

-- (g) 

db.posts.find({ "comments.commenter": "John Doe" });

-- (h) 

db.posts.aggregate([
    { $match: { content: "Life is too good" } },
    {
        $lookup: {
            from: "users",
            localField: "content",
            foreignField: "name",
            as: "user"
        }
    }
]);

-- Task-7: 

db.users.deleteMany({ telephone: { $exists: false } })