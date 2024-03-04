<?php
include 'partials/header.php';

// Find current User
$current_user_id = $_SESSION['user-id'];
$query2 = "SELECT * from usermanagement WHERE id=$current_user_id";
$result = mysqli_query($connection, $query2);
$finduser = mysqli_fetch_assoc($result);



// fetch categories from database
$query = "SELECT * FROM adminaddoffice";
$categories = mysqli_query($connection, $query);

// get back form data if form was invalid
$title = $_SESSION['user-complain-data']['title'] ?? null;
$body = $_SESSION['user-complain-data']['body'] ?? null;

// delete form data session
unset($_SESSION['user-complain-data']);
?>


<section class="form__section">
    <div class="container form__section-container">
        <h2>Submit a Complain</h2>
        <?php if (isset($_SESSION['user-complain'])) : ?>
            <div class="alert__message error">
                <p>
                    <?= $_SESSION['user-complain'];
                    unset($_SESSION['user-complain']);
                    ?>
                </p>
            </div>
        <?php endif ?>
        <form action="<?= ROOT_URL ?>user/user-complain-logic.php" enctype="multipart/form-data" method="POST">
            <input type="text" name="title" value="<?= $finduser['userid'] ?>" placeholder="User ID" readonly>
            <select name="category">
                <?php while ($category = mysqli_fetch_assoc($categories)) : ?>
                    <option value="<?= $category['id'] ?>"><?= $category['title'] ?></option>
                <?php endwhile ?>
            </select>
            <textarea style="resize:none" rows="10" name="body" placeholder="Write your complain here..."><?= $body ?></textarea>
            <div class="form__control">
                <label for="picture">Upload images & videos</label>
                <input type="file" name="picture" id="picture">
            </div>
            <button type="submit" name="submit" class="btn">Submit Complain</button>
        </form>
    </div>
</section>


<?php
include '../partials/footer.php';
?>