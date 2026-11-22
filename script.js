var passwordBox = document.getElementById("password");
var toggleButton = document.getElementById("toggle");
var bar = document.getElementById("bar");
var strengthText = document.getElementById("strength");
var scoreText = document.getElementById("score");
var tipsText = document.getElementById("tips");
var lastLabel = "-"; // remembers the previous strength label

// Show / hide the password
toggleButton.onclick = function () {
  if (passwordBox.type === "password") {
    passwordBox.type = "text";
    toggleButton.textContent = "Hide";
  } else {
    passwordBox.type = "password";
    toggleButton.textContent = "Show";
  }
};

// Mark a checklist item as passed or not passed
function setCheck(id, passed) {
  var item = document.getElementById(id);
  if (passed) {
    item.className = "pass";
  } else {
    item.className = "";
  }
}

// Runs every time the user types
function analyse() {
  var password = passwordBox.value;
  var length = password.length;
  var upper = false;
  var lower = false;
  var digit = false;
  var special = false;
  var score = 0;
  var i;

  // Check every character one by one (same idea as the C program)
  for (i = 0; i < length; i++) {
    var ch = password[i];
    if (ch >= "A" && ch <= "Z") {
      upper = true;
    } else if (ch >= "a" && ch <= "z") {
      lower = true;
    } else if (ch >= "0" && ch <= "9") {
      digit = true;
    } else {
      special = true;
    }
  }

  // Give points
  if (length >= 8) score++;
  if (length >= 12) score++;
  if (upper) score++;
  if (lower) score++;
  if (digit) score++;
  if (special) score++;

  // Very common passwords are always weak
  var common = ["password", "123456", "qwerty", "admin"];
  var isCommon = common.indexOf(password.toLowerCase()) !== -1;
  if (isCommon) {
    score = 1;
  }

  // Update the checklist
  setCheck("c-length", length >= 8);
  setCheck("c-long", length >= 12);
  setCheck("c-upper", upper);
  setCheck("c-lower", lower);
  setCheck("c-digit", digit);
  setCheck("c-special", special);

  // Strength label and bar colour
  var label = "-";
  var colour = "var(--bad)";

  if (length === 0) {
    score = 0;
  } else if (score <= 2) {
    label = "Weak";
    colour = "var(--bad)";
  } else if (score <= 4) {
    label = "Medium";
    colour = "var(--warn)";
  } else {
    label = "Strong";
    colour = "var(--good)";
  }

  bar.style.width = (score / 6) * 100 + "%";
  bar.style.background = colour;
  strengthText.textContent = "Strength: " + label;

  // Strong passwords make the bar glow
  if (label === "Strong") {
    bar.className = "strong";
  } else {
    bar.className = "";
  }

  // Make the label pop only when the strength changes
  if (label !== lastLabel) {
    strengthText.classList.remove("pop");
    void strengthText.offsetWidth; // restarts the animation
    strengthText.classList.add("pop");
    lastLabel = label;
  }
  scoreText.textContent = "Score: " + score + " / 6";

  // Tips
  var tips = "";
  if (isCommon) {
    tips = "This is a very common password. Pick something different.";
  } else if (length > 0 && score < 6) {
    tips = "Tips: ";
    if (length < 8) tips += "use at least 8 characters. ";
    if (!upper) tips += "add an uppercase letter. ";
    if (!lower) tips += "add a lowercase letter. ";
    if (!digit) tips += "add a number. ";
    if (!special) tips += "add a special character. ";
    if (length >= 8 && length < 12) tips += "12+ characters is even better.";
  }
  tipsText.textContent = tips;
}

passwordBox.oninput = analyse;
