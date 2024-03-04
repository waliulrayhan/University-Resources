<?php
include 'partials/header.php';

// fetch users from database
$user_query = "SELECT * FROM usermanagement";
$users = mysqli_query($connection, $user_query);

// Find current User
$current_user_id = $_SESSION['user-id'];

$query = "SELECT * FROM usermanagement WHERE id=$current_user_id";
$result = mysqli_query($connection, $query);
$user = mysqli_fetch_assoc($result);


// get back form data if form was invalid
$firstname = $_SESSION['use-data']['firstname'] ?? null;
$lastname = $_SESSION['user-data']['lastname'] ?? null;
$email = $_SESSION['user-data']['email'] ?? null;
$oldpassword = $_SESSION['user-data']['oldpassword'] ?? null;
$newpassword = $_SESSION['user-data']['newpassword'] ?? null;

?>
<section class="posts">
    </br>
    </br>

    <?php if (isset($_SESSION['edit-post'])) : ?>
        <div class="alert__message error">
            <p>
                <?= $_SESSION['edit-post'];
                unset($_SESSION['edit-post']);
                ?>
            </p>
        </div>
    <?php endif ?>

    <form action="<?= ROOT_URL ?>user/user-profile-logic.php" enctype="multipart/form-data" method="POST">

        <input type="hidden" name="id" value="<?= $user['id'] ?>">
        <input type="hidden" name="previous_picture_name" value="<?= $user['picture'] ?>">

        <img src="<?= ROOT_URL . 'images/' . $user['picture'] ?>" width="400" height="200">


        </br>

        <input class="form-control form-control-sm" type="file" name="picture" id="picture">
        <label>
            <h6>Update Your Profile Picture</h6>
        </label>

        <center>
            <h4>Your Profile</h4>
            <span>Account Status - </span>
            <label><?= $user['stat'] ?></label>
        </center>

        <label>
            <h5>
                User Info
            </h5>
        </label>
        <label>User ID</label>
        <input type="text" name="userid" value="<?= $user['userid'] ?>" placeholder="User ID" readonly>

        <label>First Name</label>
        <input type="text" name="firstname" value="<?= $user['firstname'] ?>" placeholder="First Name">

        <label>Last Name</label>
        <input type="text" name="lastname" value="<?= $user['lastname'] ?>" placeholder="Last Name">

        <label>E-mail</label>
        <input type="text" name="email" value="<?= $user['email'] ?>" placeholder="E-mail">

        <label>
            <h5>
                Security
            </h5>
        </label>
        <label>Current Password</label>
        <input type="password" name="oldpassword" placeholder="Current Password">

        <label>New Password</label>
        <input type="password" name="newpassword" placeholder="New Password">

        <button type="submit" name="submit" class="btn">Update Profile</button>
    </form>

    </br>
    </br>
</section>

<?php
include '../partials/footer.php';
?>